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


GPIO_InitTypeDef LEDS;
GPIO_InitTypeDef Push;


int main(void)
{
    HAL_Init();

    /* we need to enable the GPIOA port's clock first */
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();


    LEDS.Pin = GPIO_PIN_9 | GPIO_PIN_10 |  GPIO_PIN_8 | GPIO_PIN_7;	/* setting up 4 pins at once with | operator */
    LEDS.Mode = GPIO_MODE_OUTPUT_PP;		/* configure as output, in push-pull mode */
    LEDS.Pull = GPIO_NOPULL;			/* we don't need internal pull-up or -down resistor */
    LEDS.Speed = GPIO_SPEED_FAST;		/* we need a high-speed output */

    HAL_GPIO_Init(GPIOF, &LEDS);		/* initialize the pin on GPIOF port */

    Push.Pin = GPIO_PIN_4;
       Push.Mode = GPIO_MODE_INPUT;
       Push.Pull = GPIO_NOPULL;
       Push.Speed = GPIO_SPEED_FAST;

       HAL_GPIO_Init(GPIOB, &Push);

    int swich = 0;
    int counter = 0;
    while (1) {
    	int pushing = 0;
    	        	 while(HAL_GPIO_ReadPin(GPIOB, Push.Pin)) {
    	        		 	 HAL_Delay(250);
    	        		 pushing++;
    	        		 if (pushing == 1){
    	        			 swich = (swich == 0);
    	        		 }
    	        	 }
        if(swich == 0){
        	counter ++;
        	if (counter >= 5)
        		counter = 1;
        }
        	if (swich == 1){
        		counter--;
        	if (counter <= 0)
        	 counter = 5;
        	}
    	if ( counter == 1){
    	     HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);

    	}
     	if ( counter == 2){
        	     HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);

        	}
    	if (counter == 3){
        	     HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);

        	}
    	if (counter == 4){
            	     HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
            	}

        HAL_Delay(80);
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
    }
}

