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

/* create a config structure */

uint32_t last_debounce_time = 0;    // the last time the output pin was toggled
const uint32_t debounce_delay = 200; // the debounce time in ms (increase if the output flickers)

GPIO_InitTypeDef Button;

volatile int counter = 0;
void init_button() {
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;

	Button.Pin = GPIO_PIN_4;
	Button.Mode = GPIO_MODE_IT_RISING;
	Button.Pull = GPIO_NOPULL;
	Button.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOB, &Button);

	HAL_NVIC_SetPriority(EXTI4_IRQn, 4, 0);
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);

}

int main(void) {
	HAL_Init();
	init_button();

	BSP_LED_Init(LED_GREEN);

	while (1) {

	}
}

void EXTI4_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(Button.Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	if (GPIO_Pin == GPIO_PIN_4) {
		uint32_t current_time = HAL_GetTick();
		if (current_time < last_debounce_time + debounce_delay) { // Do nothing (this is not a real button press)
			return;
		} else {
			counter++;
			if (counter == 5) {
				BSP_LED_Toggle(LED1);
				counter = 0;
			}
		}
		last_debounce_time = current_time;
	}
}

