#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

TIM_HandleTypeDef TimHandle_RED;
TIM_HandleTypeDef TimHandle_BLUE;
TIM_HandleTypeDef TimHandle_GREEN;
GPIO_InitTypeDef user_button_handle;
TIM_OC_InitTypeDef sConfig;
GPIO_InitTypeDef Led_RED;
GPIO_InitTypeDef Led_GREEN;
GPIO_InitTypeDef Led_BLUE;

volatile uint32_t last_debounce_time = 0; // the last time the output pin was toggled
volatile const uint32_t debounce_delay = 50; // the debounce time in ms (increase if the output flickers)
volatile int pulse_red = 100;
volatile int pulse_green = 100;
volatile int pulse_blue = 100;
volatile uint32_t pushing_time = 0;
volatile uint32_t release_time = 0;
volatile int led_counter = 0;
volatile int push_button = 0;
void Error_Handler(void);
void SystemClock_Config(void);

// normal timer
void init_tims_with_config() {
	__HAL_RCC_TIM2_CLK_ENABLE()
	;
	TimHandle_RED.Instance = TIM2;
	TimHandle_RED.Init.Prescaler = 108 - 1; // 108000000 / 10800 = 10000 -> speed of 1 count-up: 1 /10000 s = 0.1 ms
	TimHandle_RED.Init.Period = 100 - 1; // 10000 x 0.1 ms = 1000 ms = 1.0 s period */
	TimHandle_RED.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle_RED.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configure the timer */
	HAL_TIM_PWM_Init(&TimHandle_RED);

	__HAL_RCC_TIM3_CLK_ENABLE()
	;
	TimHandle_BLUE.Instance = TIM3;
	TimHandle_BLUE.Init.Prescaler = 108 - 1; // 108000000 / 10800 = 10000 -> speed of 1 count-up: 1 /10000 s = 0.1 ms
	TimHandle_BLUE.Init.Period = 100 - 1; // 10000 x 0.1 ms = 1000 ms = 1.0 s period */
	TimHandle_BLUE.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle_BLUE.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configure the timer */
	HAL_TIM_PWM_Init(&TimHandle_BLUE);

	__HAL_RCC_TIM5_CLK_ENABLE()
	;
	TimHandle_GREEN.Instance = TIM5;
	TimHandle_GREEN.Init.Prescaler = 108 - 1; // 108000000 / 10800 = 10000 -> speed of 1 count-up: 1 /10000 s = 0.1 ms
	TimHandle_GREEN.Init.Period = 100 - 1; // 10000 x 0.1 ms = 1000 ms = 1.0 s period */
	TimHandle_GREEN.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle_GREEN.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configure the timer */
	HAL_TIM_PWM_Init(&TimHandle_GREEN);
	/* output compare config ***********************************************************************************************/
	sConfig.Pulse = 50;
	/* 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high; our eyes are not able to notice, that it is a vibrating light */
	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfig.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&TimHandle_RED, &sConfig, TIM_CHANNEL_1);
	HAL_TIM_PWM_ConfigChannel(&TimHandle_BLUE, &sConfig, TIM_CHANNEL_1);
	HAL_TIM_PWM_ConfigChannel(&TimHandle_GREEN, &sConfig, TIM_CHANNEL_4);
}
void init_leds() {
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	Led_RED.Pin = GPIO_PIN_15;
	Led_RED.Mode = GPIO_MODE_AF_OD; /* configure as output, in Open Drain mode */
	Led_RED.Pull = GPIO_NOPULL;
	Led_RED.Speed = GPIO_SPEED_HIGH;
	Led_RED.Alternate = GPIO_AF1_TIM2; /* this alternate function we need to use TIM2 in output compare mode */
	HAL_GPIO_Init(GPIOA, &Led_RED);

	__HAL_RCC_GPIOB_CLK_ENABLE()
	;
	Led_GREEN.Pin = GPIO_PIN_4;
	Led_GREEN.Mode = GPIO_MODE_AF_OD; /* configure as output, in Open Drain mode */
	Led_GREEN.Pull = GPIO_NOPULL;
	Led_GREEN.Speed = GPIO_SPEED_HIGH;
	Led_GREEN.Alternate = GPIO_AF2_TIM3; /* this alternate function we need to use TIM3 in output compare mode */
	HAL_GPIO_Init(GPIOB, &Led_GREEN);

	__HAL_RCC_GPIOI_CLK_ENABLE()
	;
	Led_BLUE.Pin = GPIO_PIN_0;
	Led_BLUE.Mode = GPIO_MODE_AF_OD; /* configure as output, in Open Drain mode */
	Led_BLUE.Pull = GPIO_NOPULL;
	Led_BLUE.Speed = GPIO_SPEED_HIGH;
	Led_BLUE.Alternate = GPIO_AF2_TIM5; /* this alternate function we need to use TIM4 in output compare mode */
	HAL_GPIO_Init(GPIOI, &Led_BLUE);

}

void init_user_button(void) {
	__HAL_RCC_GPIOI_CLK_ENABLE()
	; /* enable the GPIOI clock */

	user_button_handle.Pin = GPIO_PIN_11;
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST;
	user_button_handle.Mode = GPIO_MODE_IT_RISING_FALLING;
	HAL_GPIO_Init(GPIOI, &user_button_handle);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void current_led_power() {
	if (led_counter == 0) {
		pulse_red -= 10;
		if (pulse_red < 0) {
			pulse_red = 100;
		}
	} else if (led_counter == 1) {
		pulse_green -= 10;
		if (pulse_green < 0) {
			pulse_green = 100;
		}
	} else if (led_counter == 2) {
		pulse_blue -= 10;
		if (pulse_blue < 0) {
			pulse_blue = 100;
		}
	}

}
int main(void) {
	HAL_Init();
	SystemClock_Config();
	init_tims_with_config();
	init_leds();
	init_user_button();
	HAL_TIM_PWM_Start(&TimHandle_RED, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&TimHandle_BLUE, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&TimHandle_GREEN, TIM_CHANNEL_4);

	while (1) {

		__HAL_TIM_SET_COMPARE(&TimHandle_RED, TIM_CHANNEL_1, pulse_red);
		__HAL_TIM_SET_COMPARE(&TimHandle_GREEN, TIM_CHANNEL_4, pulse_green);
		__HAL_TIM_SET_COMPARE(&TimHandle_BLUE, TIM_CHANNEL_1, pulse_blue);
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
			if (push_button == 0) {
				push_button = 1;
				pushing_time = current_time;
			} else if (push_button == 1) {
				push_button = 0;
				release_time = current_time;
				if ((release_time - pushing_time) > 500) {
					led_counter++;
					if (led_counter == 3) {
						led_counter = 0;
					}
				} else {
					current_led_power();
				}
			}
		}

	}

	last_debounce_time = current_time;
}
void Error_Handler(void) {
}

void SystemClock_Config(void) {
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
