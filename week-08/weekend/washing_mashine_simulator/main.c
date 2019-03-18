#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include "fonts.h"

TIM_HandleTypeDef TimHandle;
GPIO_InitTypeDef user_button;
uint32_t last_debounce_time = 0;    // the last time the output pin was toggled
const uint32_t debounce_delay = 50; // the debounce time in ms (increase if the output flickers)
static void Error_Handler(void);
static void SystemClock_Config(void);
static uint8_t spin = 0;
volatile int button_push = 0;
uint32_t push = 0;
uint32_t release = 0;
volatile int drying_counter = 0;
volatile int program_counter = 0;
volatile int washing_time = 0;
typedef enum {
	STOPPED, WASHING, DRYING
} machine_state_t;

volatile machine_state_t state = STOPPED;
volatile uint16_t rpm = 800;

void lcd_init() {
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
	BSP_LCD_SelectLayer(1);
	BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_Clear(LCD_COLOR_BLACK);
	BSP_LCD_SetTransparency(1, 150);
}

void lcd_draw_machine() {
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_FillRect(BSP_LCD_GetXSize() / 2 - 100, 5, 200,
			BSP_LCD_GetYSize() - 10);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_DrawHLine(BSP_LCD_GetXSize() / 2 - 100, 60, 200);
	BSP_LCD_DrawCircle(BSP_LCD_GetXSize() / 2 + 35, 32, 15);

	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	BSP_LCD_DrawCircle(BSP_LCD_GetXSize() / 2, BSP_LCD_GetYSize() / 2 + 40, 70);

	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);

	BSP_LCD_SetFont(&Font12);

	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font12);

	BSP_LCD_DisplayStringAt(300, 10, "800", LEFT_MODE);
	BSP_LCD_DisplayStringAt(300, 17 + 10, "1000", LEFT_MODE);

	BSP_LCD_DisplayStringAt(300, 34 + 10, "1200", LEFT_MODE);

}

/* draw a line from the circle center point */
void lcd_print_mode() {
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	BSP_LCD_SetBackColor(LCD_COLOR_GRAY);
	BSP_LCD_SetFont(&Font16);

	if (state == STOPPED) {
		BSP_LCD_DisplayStringAt(160, 25, "STOPPED", LEFT_MODE);

	} else if (state == WASHING) {
		BSP_LCD_DisplayStringAt(160, 25, "WASHING", LEFT_MODE);

	} else if (state == DRYING) {
		BSP_LCD_DisplayStringAt(160, 25, "DRYING", LEFT_MODE);

	}
}

void lcd_set_rpm_handle() {
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);

	BSP_LCD_DrawCircle(BSP_LCD_GetXSize() / 2 + 35, 32, 15);

	if (rpm == 800) {
		BSP_LCD_DrawLine(BSP_LCD_GetXSize() / 2 + 35, 32,
				BSP_LCD_GetXSize() / 2 + 40, 25);

	} else if (rpm == 1000) {
		BSP_LCD_DrawLine(BSP_LCD_GetXSize() / 2 + 35, 32,
				BSP_LCD_GetXSize() / 2 + 45, 32);

	} else if (rpm == 1200) {
		BSP_LCD_DrawLine(BSP_LCD_GetXSize() / 2 + 35, 32,
				BSP_LCD_GetXSize() / 2 + 40, 39);
	}
}

void lcd_spin_drum() {
	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	if (spin == 0) {
		BSP_LCD_DrawLine(BSP_LCD_GetXSize() / 2,
				BSP_LCD_GetYSize() / 2 + 40 + 70, BSP_LCD_GetXSize() / 2,
				BSP_LCD_GetYSize() / 2 + 40 - 70);
	} else if (spin == 1) {
		BSP_LCD_DrawLine(BSP_LCD_GetXSize() / 2 + 36.77,
				BSP_LCD_GetYSize() / 2 + 40 - 59.56,
				BSP_LCD_GetXSize() / 2 - 36.77,
				BSP_LCD_GetYSize() / 2 + 40 + 59.56);
	} else if (spin == 2) {
		BSP_LCD_DrawLine(BSP_LCD_GetXSize() / 2 + 59.56,
				BSP_LCD_GetYSize() / 2 + 40 - 36.77,
				BSP_LCD_GetXSize() / 2 - 59.56,
				BSP_LCD_GetYSize() / 2 + 40 + 36.77);
	} else if (spin == 3) {
		BSP_LCD_DrawLine(BSP_LCD_GetXSize() / 2 - 70,
				BSP_LCD_GetYSize() / 2 + 40, BSP_LCD_GetXSize() / 2 + 70,
				BSP_LCD_GetYSize() / 2 + 40);
	} else if (spin == 4) {
		BSP_LCD_DrawLine(BSP_LCD_GetXSize() / 2 - 59.56,
				BSP_LCD_GetYSize() / 2 + 40 - 36.77,
				BSP_LCD_GetXSize() / 2 + 59.56,
				BSP_LCD_GetYSize() / 2 + 40 + 36.77);
	} else if (spin == 5) {
		BSP_LCD_DrawLine(BSP_LCD_GetXSize() / 2 - 36.77,
				BSP_LCD_GetYSize() / 2 + 40 - 59.56,
				BSP_LCD_GetXSize() / 2 + 36.77,
				BSP_LCD_GetYSize() / 2 + 40 + 59.56);
		spin = -1;
	}

	spin++;
}

void init_user_button(void) {
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;
	user_button.Pin = GPIO_PIN_11;
	user_button.Pull = GPIO_NOPULL;
	user_button.Speed = GPIO_SPEED_FAST;
	user_button.Mode = GPIO_MODE_IT_RISING_FALLING;
	HAL_GPIO_Init(GPIOI, &user_button);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_tim2() {

	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	HAL_TIM_Base_DeInit(&TimHandle);
	TimHandle.Instance = TIM2;
	TimHandle.Init.Prescaler = 10800 - 1; // 108000000 / 10800 = 10000 -> speed of 1 count-up: 1 /10000 s = 0.1 ms
	TimHandle.Init.Period = 10000 - 1; // 10000 x 0.1 ms = 1000 ms = 1.0 s period */
	TimHandle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&TimHandle);
	HAL_NVIC_SetPriority(TIM2_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void washing() {
	lcd_draw_machine();
	lcd_print_mode();
	lcd_set_rpm_handle();
	lcd_spin_drum();
	HAL_Delay(1000 / 6);
}

void drying() {
	lcd_draw_machine();
	lcd_print_mode();
	lcd_set_rpm_handle();
	lcd_spin_drum();
	if (rpm == 800)
		HAL_Delay(750 / 6);
	else if (rpm == 1000)
		HAL_Delay(500 / 6);
	else if (rpm == 1200)
		HAL_Delay(250 / 6);
}

int main(void) {
	HAL_Init();
	SystemClock_Config();
	init_tim2();
	init_user_button();
	lcd_init();
	lcd_draw_machine();
	lcd_print_mode();
	lcd_spin_drum();
	lcd_set_rpm_handle();

	HAL_TIM_Base_Start_IT(&TimHandle);
	while (1) {
		if (state == WASHING) {
			washing();
		} else if (state == DRYING) {
			drying();
		}
	}
}

void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	uint32_t current_time = HAL_GetTick();
	if (current_time < last_debounce_time + debounce_delay) { // Do nothing (this is not a real button press)
		return;
	} else {
		if (GPIO_Pin == GPIO_PIN_11) {
			if (button_push == 0) {
				button_push = 1;
				push = current_time;
			} else if (button_push == 1) {
				button_push = 0;
				release = current_time;
				if (washing_time == 0 && state == STOPPED) {
					washing_time = release - push;
				} else if (washing_time != 0 && state == STOPPED) {
					program_counter++;
				}

			}
		}
		last_debounce_time = current_time;
	}
}

void TIM2_IRQHandler() {
	HAL_TIM_IRQHandler(&TimHandle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TimHandle.Instance) {
		if (HAL_GetTick() - release > 2000 && washing_time != 0
				&& state == STOPPED) {
			state = WASHING;
			if (program_counter <= 1) {
				rpm = 800;
			} else if (program_counter == 2) {
				rpm = 1000;
			} else if (program_counter > 2) {
				rpm = 1200;
			}
			program_counter = 0;
		} else if (state == WASHING) {
			washing_time -= 1000;
			if (washing_time <= 0) {
				washing_time = 0;
				state = DRYING;
			}
		} else if (state == DRYING) {
			drying_counter++;
			if (drying_counter == 5) {
				state = STOPPED;
				drying_counter = 0;
				lcd_print_mode();
			}
		}
	}
}
static void Error_Handler(void) {
}

static void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}
