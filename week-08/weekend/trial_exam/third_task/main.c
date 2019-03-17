#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

TIM_HandleTypeDef TimHandle;
static void Error_Handler(void);
static void SystemClock_Config(void);
#define UART_PUTCHAR int __io_putchar(int ch)
GPIO_InitTypeDef user_button;
UART_HandleTypeDef UartHandle;
uint32_t last_debounce_time = 0;    // the last time the output pin was toggled
const uint32_t debounce_delay = 50; // the debounce time in ms (increase if the output flickers)
int timer = 0;

typedef enum {
	OPEN,  		//In this state the LED_GREEN should be flashing with 0.5Hz, 50% duty cycle
				//When the system gets a signal that a train is approaching the crossing (blue button click) it has to enter the SECURING state.
	SECURING,	//After entering the SECURING state the system has to close the barrier which this takes exactly 5 seconds.
			 	//In this state the LED_GREEN should be flashing with 1Hz, 50% duty cycle.
				//During this time the system should not react to any signal (blue button click).
	SECURED, 	//Once the barrier is down the system enters the SECURED state.
				// In this state the LED_GREEN is turned off.
	OPENING, 	//When the system gets a signal that a train has left the crossing (blue button click) it switches to OPENING state.
				// In this state the system lifts the barrier which takes exactly 6 seconds (it's a heavy barrier so it takes more time to lift).
				//In this state the LED_GREEN is flashing with 1Hz, 50% duty cycle.
				//During this time the system should not react to any signal (blue button click).
				//Once the barrier is up the system gets back to its initial state (OPEN).
} state_t;

state_t current_state = OPEN;

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

void led_toggle(int waiting) {
	int tickstart = HAL_GetTick();

	while (HAL_GetTick() - tickstart != waiting) {
	}
	BSP_LED_Toggle(LED1);
}


void init_blue_button(void) {
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;
	user_button.Pin = GPIO_PIN_11;
	user_button.Pull = GPIO_NOPULL;
	user_button.Speed = GPIO_SPEED_FAST;
	user_button.Mode = GPIO_MODE_IT_RISING;
	HAL_GPIO_Init(GPIOI, &user_button);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_uart(void) {
	__HAL_RCC_USART1_CLK_ENABLE()
	;
	UartHandle.Instance = USART1;
	UartHandle.Init.BaudRate = 115200;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits = UART_STOPBITS_1;
	UartHandle.Init.Parity = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode = UART_MODE_TX_RX;
	BSP_COM_Init(COM1, &UartHandle);
}

int main(void) {
	HAL_Init();
	SystemClock_Config();
	init_uart();
	init_tim2();
	init_blue_button();
	BSP_LED_Init(LED1);

	HAL_TIM_Base_Start_IT(&TimHandle);

	printf("Entered in OPEN state\r\n");
	while (1) {
		if (current_state == OPEN)
			led_toggle(250);
		else if (current_state == SECURING)
			led_toggle(500);
		else if (current_state == SECURED)
			BSP_LED_Off(LED1);
		else if (current_state == OPENING)
			led_toggle(500);
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
			if (current_state == OPEN) {
				current_state = SECURING;
				printf("Entered in SECURING state\r\n");
			}else if(current_state == SECURED){
				current_state = OPENING;
				printf("Entered in OPENING state\r\n");
			}
		}
	}
	last_debounce_time = current_time;
}

void TIM2_IRQHandler() {
	HAL_TIM_IRQHandler(&TimHandle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TimHandle.Instance) {
		if (current_state == SECURING) {
			timer++;
			if (timer == 5) {
				current_state = SECURED;
				printf("Entered in SECURED state\r\n");
				timer = 0;
			}
		}else if (current_state == OPENING) {
			timer++;
			if (timer == 6) {
				current_state = OPEN;
				printf("Entered in OPEN state\r\n");
				timer = 0;
			}
		}
	}
}

UART_PUTCHAR {
	HAL_UART_Transmit(&UartHandle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
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
