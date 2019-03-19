#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

#define UART_PUTCHAR int __io_putchar(int ch)
UART_HandleTypeDef UartHandle;
TIM_OC_InitTypeDef sConfig;
GPIO_InitTypeDef gpio_adc_pin;
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_channel_config;
static void SystemClock_Config(void);
static void Error_Handler(void);
int joyX = 0;
int joyY = 0;


void init_uart() {
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

void init_joystick() {
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	gpio_adc_pin.Mode = GPIO_MODE_ANALOG;
	gpio_adc_pin.Pin = GPIO_PIN_0;
	gpio_adc_pin.Speed = GPIO_SPEED_FAST;
	gpio_adc_pin.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &gpio_adc_pin);

	__HAL_RCC_GPIOF_CLK_ENABLE()
	;
	gpio_adc_pin.Mode = GPIO_MODE_ANALOG;
	gpio_adc_pin.Pin = GPIO_PIN_10;
	gpio_adc_pin.Speed = GPIO_SPEED_FAST;
	gpio_adc_pin.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOF, &gpio_adc_pin);

	__HAL_RCC_ADC3_CLK_ENABLE()
	;
	adc_handle.Instance = ADC3;
	adc_handle.Init.ScanConvMode = ADC_SCAN_ENABLE;
	adc_handle.Init.ContinuousConvMode = ENABLE;
	adc_handle.Init.NbrOfConversion = 2;
	HAL_ADC_Init(&adc_handle);

	adc_channel_config.Channel = ADC_CHANNEL_0;
	adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;
	adc_channel_config.Rank = 1;
	HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);

	adc_channel_config.Channel = ADC_CHANNEL_8;
	adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;
	adc_channel_config.Rank = 2;
	HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);

}

int main(void) {
	HAL_Init();
	SystemClock_Config();
	init_uart();
	init_joystick();


	while (1) {
		HAL_Delay(1000);
		HAL_ADC_Start(&adc_handle);
		if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
		//	if (1000 < joyX - (HAL_ADC_GetValue(&adc_handle))) {

			joyX = HAL_ADC_GetValue(&adc_handle);
			printf("X %d.\n", joyX);
			//}
		}
		if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
			//if (1000 < joyY - (HAL_ADC_GetValue(&adc_handle))) {
			joyY = HAL_ADC_GetValue(&adc_handle);
			printf("Y: %d.\n", joyY);
		//	}
		}
		HAL_ADC_Stop(&adc_handle);


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
