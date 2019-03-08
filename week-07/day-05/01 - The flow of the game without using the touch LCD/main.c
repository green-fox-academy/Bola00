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
#include <string.h>

GPIO_InitTypeDef GPIOTxConfig;
GPIO_InitTypeDef GPIORxConfig;

RNG_HandleTypeDef rng_handle;
UART_HandleTypeDef UartHandle;
GPIO_InitTypeDef LED;
GPIO_InitTypeDef Push;

#define UART_PUTCHAR int __io_putchar(int ch)

void init()
{

	    /* enable GPIO clock */
	    __HAL_RCC_GPIOA_CLK_ENABLE();
	    __HAL_RCC_GPIOB_CLK_ENABLE();
	    __HAL_RCC_GPIOF_CLK_ENABLE();

	    /* configure GPIO for UART transmit line */
	    GPIOTxConfig.Pin = GPIO_PIN_9;
	    GPIOTxConfig.Mode = GPIO_MODE_AF_PP;
	    GPIOTxConfig.Pull = GPIO_NOPULL;
	    GPIOTxConfig.Speed = GPIO_SPEED_FAST;
	    GPIOTxConfig.Alternate = GPIO_AF7_USART1;

	    HAL_GPIO_Init(GPIOA, &GPIOTxConfig);

	    /* configure GPIO for UART receive line */
	    GPIORxConfig.Pin = GPIO_PIN_7;
	    GPIORxConfig.Mode = GPIO_MODE_AF_PP;
	    GPIOTxConfig.Pull = GPIO_NOPULL;
	    GPIORxConfig.Speed = GPIO_SPEED_FAST;
	    GPIORxConfig.Alternate = GPIO_AF7_USART1;

	    HAL_GPIO_Init(GPIOB, &GPIORxConfig);

	    /* enable the clock of the used peripherial instance */
	    __HAL_RCC_USART1_CLK_ENABLE();

	    /* defining the UART configuration structure */
	    UartHandle.Instance = USART1;
	    UartHandle.Init.BaudRate = 115200;
	    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	    UartHandle.Init.StopBits = UART_STOPBITS_1;
	    UartHandle.Init.Parity = UART_PARITY_NONE;
	    UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	    UartHandle.Init.Mode = UART_MODE_TX_RX;

	    HAL_UART_Init(&UartHandle);

	    LED.Pin = GPIO_PIN_10; 	/* setting up 1 pins at once with | operator */
	      LED.Mode = GPIO_MODE_OUTPUT_PP;		/* configure as output, in push-pull mode */
	      LED.Pull = GPIO_NOPULL;			/* we don't need internal pull-up or -down resistor */
	      LED.Speed = GPIO_SPEED_FAST;		/* we need a high-speed output */

	      HAL_GPIO_Init(GPIOF, &LED);		/* initialize the pin on GPIOF port */

	      Push.Pin = GPIO_PIN_4;
	      Push.Mode = GPIO_MODE_INPUT;
	      Push.Pull = GPIO_NOPULL;
	      Push.Speed = GPIO_SPEED_FAST;

	      HAL_GPIO_Init(GPIOB, &Push);


	      __HAL_RCC_RNG_CLK_ENABLE();

	      rng_handle.Instance = RNG;

	      HAL_RNG_Init(&rng_handle);
}
int active_waiting(int waiting){
	int tickstart = HAL_GetTick();

	while (HAL_GetTick() - tickstart < waiting){
		if (HAL_GPIO_ReadPin(GPIOB, Push.Pin))
			return 1;
	}
	return 0;
}

int main(void)
{
	 HAL_Init();
	 init();

	 printf("Let's play a game! Are you ready?\n");
		 while(1) {
	       	 HAL_GPIO_WritePin(GPIOF, LED.Pin, GPIO_PIN_SET);
	       	if(active_waiting(500))
	       		break;
	    	 HAL_GPIO_WritePin(GPIOF, LED.Pin, GPIO_PIN_RESET);
	    		if(active_waiting(500))
	    		       		break;

	    }
		 printf("start!\n");
    	 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);

    	 int random_flash;
    while (1) {

    	 uint32_t random_number = HAL_RNG_GetRandomNumber(&rng_handle);
    	 random_flash = random_number % 10 + 1;

    	 HAL_Delay(random_flash * 1000);
       	 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
       	 int starting_time = HAL_GetTick();

    	 while(!HAL_GPIO_ReadPin(GPIOB, Push.Pin)) {
    	 }
     	 int ending_time = HAL_GetTick();
     	 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);

     	 printf("your time: %d\n", ending_time - starting_time);
     	 break;
    }
}

UART_PUTCHAR
{
    HAL_UART_Transmit(&UartHandle, (uint8_t*)&ch, 1, 0xFFFF);
    return ch;
}




