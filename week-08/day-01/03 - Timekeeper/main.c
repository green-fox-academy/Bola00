#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <string.h>
#define UART_PUTCHAR int __io_putchar(int ch)

UART_HandleTypeDef UartHandle;

/* the timer's config structure */
TIM_HandleTypeDef TimHandle;

uint16_t tim_val = 0; /* variable to store the actual value of the timer's register (CNT) */
uint16_t seconds = 0; /* variable to store the value of ellapsed seconds */

static void Error_Handler(void);
static void SystemClock_Config(void);
GPIO_InitTypeDef LEDS;

int main(void) {
	HAL_Init();

	/* this function call sets the timers input clock to 108 Mhz (=108000000 Hz) */
	SystemClock_Config();

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

	printf("Set the timer in this format: wx.yz\r\n");
	uint8_t time_as_string[5];
	HAL_UART_Receive(&UartHandle, (uint8_t*) time_as_string, 5, 0xFFFF);

	strcat(time_as_string, "\0");
	char *token1 = strtok(time_as_string, ".");
	char *token2 = strtok(NULL, "\0");
	int user_number = atoi(token1) * 100;
	user_number += atoi(token2);

	/* we need to enable the TIM2 */
	__HAL_RCC_TIM2_CLK_ENABLE()
	;
	TimHandle.Instance = TIM2;
	TimHandle.Init.Prescaler = 54000 - 1; /* 108000000/54000 = 2000 -> speed of 1 count-up: 1/2000 sec = 0.5 ms */
	TimHandle.Init.Period = 50 - 1;
	TimHandle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configure the timer */
	HAL_TIM_Base_Init(&TimHandle);

	/* starting the timer */
	HAL_TIM_Base_Start(&TimHandle);

	printf("user number: %d\r\n", user_number);
	int second_counter = 0;

	while (1) {
		tim_val = __HAL_TIM_GET_COUNTER(&TimHandle);

		if (tim_val == 49){
			second_counter++;
			if (second_counter % 10 == 0){
				printf("%d.%d seconds elapsed.\r\n", second_counter / 100,
						second_counter % 100);
			}
		}
		if (second_counter == user_number)
			HAL_NVIC_SystemReset();
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
UART_PUTCHAR {
	HAL_UART_Transmit(&UartHandle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}
