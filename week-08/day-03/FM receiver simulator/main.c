/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
# include <string.h>
#define UART_PUTCHAR int __io_putchar(int ch)
UART_HandleTypeDef UartHandle;

uint32_t last_debounce_time = 0;    // the last time the output pin was toggled
const uint32_t debounce_delay = 50; // the debounce time in ms (increase if the output flickers)

static void Error_Handler(void);
static void SystemClock_Config(void);

GPIO_InitTypeDef buttons;

volatile int pushing_button = 0;
volatile int volume = 50;
volatile int frekquency = 875;

volatile uint32_t pushing;
volatile uint32_t releasing;

typedef struct {
	char* name;
	int channel_frekquency;

} Channel_t;

Channel_t channel_list[5];

void find_closest_radio(int up_or_down) {

	if (up_or_down == 1) {
		for (;;) {
			frekquency += 1;
			if (frekquency == 1080) {
				frekquency = 875;
			} else {
				for (int i = 0; i < sizeof(channel_list) / sizeof(Channel_t);
						i++) {
					if (frekquency == channel_list[i].channel_frekquency)
						return;
				}
			}
		}
	}
	if (up_or_down == 0) {
		for (;;) {
			frekquency -= 1;
			if (frekquency == 875) {
				frekquency = 1080;
			} else {
				for (int i = 0; i < sizeof(channel_list) / sizeof(Channel_t); i++) {
					if (frekquency == channel_list[i].channel_frekquency)
						return;
				}
			}
		}
	}
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

void init_button() {
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;
	buttons.Pin = GPIO_PIN_9 | GPIO_PIN_8 | GPIO_PIN_7 | GPIO_PIN_6;
	buttons.Mode = GPIO_MODE_IT_RISING_FALLING;
	buttons.Pull = GPIO_NOPULL;
	buttons.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOF, &buttons);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 4, 0);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}

void channel_maker() {
	channel_list[0].name = "Inforadio";
	channel_list[0].channel_frekquency = 881;
	channel_list[1].name = "Music_FM";
	channel_list[1].channel_frekquency = 895;
	channel_list[2].name = "Jazzy_Radio";
	channel_list[2].channel_frekquency = 909;
	channel_list[3].name = "Klasszik_Radio";
	channel_list[3].channel_frekquency = 921;
	channel_list[4].name = "Klubradio";
	channel_list[4].channel_frekquency = 929;
}

void print_status() {
	char current_channel_name[20] = "NO_CHANNEL";

	for (int i = 0; i < sizeof(channel_list) / sizeof(Channel_t); i++){
		if (frekquency == channel_list[i].channel_frekquency)
			strcpy(current_channel_name, channel_list[i].name);
	}

	printf("volume: %d frekquency: %i.%i channel: %s\r\n", volume, frekquency / 10, frekquency % 10, current_channel_name);
}
int main(void) {
	HAL_Init();
	SystemClock_Config();
	init_button();
	init_uart();
	channel_maker();
	while (1) {

	}
}

void EXTI9_5_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	uint32_t current_time = HAL_GetTick();
	if (current_time < last_debounce_time + debounce_delay) { // Do nothing (this is not a real button press)
		return;
	} else {
		if (pushing_button == 0) {
			pushing_button = 1;
			pushing = HAL_GetTick();
		} else if (pushing_button == 1) {
			pushing_button = 0;
			releasing = HAL_GetTick();
			uint32_t pushing_time = releasing - pushing;
			if (GPIO_Pin == GPIO_PIN_8) {
				if (pushing_time < 1000) {
					if (volume != 0)
						volume--;
				} else {
					if (volume >= 5)
						volume -= 5;
					else
						volume = 0;
				}
			} else if (GPIO_Pin == GPIO_PIN_9) {
				if (pushing_time < 1000) {
					if (volume != 100)
						volume++;
				} else {
					if (volume <= 95)
						volume += 5;
					else
						volume = 100;
				}
			} else if (GPIO_Pin == GPIO_PIN_7) {
				if (pushing_time < 1000) {
					if (frekquency < 1080)
						frekquency += 1;
					else
						frekquency = 875;
				} else {
					find_closest_radio(1);
				}
			} else if (GPIO_Pin == GPIO_PIN_6) {
				if (pushing_time < 1000) {
					if (frekquency > 875)
						frekquency -= 0.1;
					else
						frekquency = 1080;
				} else {
					find_closest_radio(0);
				}
			}
			print_status();
		}
	}
	last_debounce_time = current_time;
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

