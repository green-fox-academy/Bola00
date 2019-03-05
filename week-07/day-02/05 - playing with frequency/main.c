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

/*
Flash the user LED with gradually increasing frequency.
Start from 0.5 Hz and constantly make it 1 Hz,
then 2 Hz finally 4 Hz, then it should constantly decrease the frequency from 4 Hz back to 0.5 Hz.
(increase/decrease the frequency, when 3 period - on and off - comes to an end)
*/
int main(void)
{
    HAL_Init();

    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

    BSP_LED_Init(LED1);

    while (1) {
    	 if (BSP_PB_GetState(BUTTON_KEY)) {

    		 	 int swich = 0;
    		 	 int delay_high = 2000;
    		 	 	 BSP_LED_On(LED1);
    	             HAL_Delay(delay_high);
    	             BSP_LED_Off(LED1);
    	             HAL_Delay(delay_high);
    	             for(int i = 0; i < 18; i++){
    	            	 if(delay_high == 2000 || delay_high == 250){
    	            		 if(swich == 0){
    	            			 swich = 1;
    	            		 }else{
    	            			swich = 0;
    	            		 }
    	            		 }
    	             if(swich == 1){

    	            	 	 delay_high /= 2;
    	             }else{
    	            	 delay_high *= 2;
    	             }
    	            	 	 BSP_LED_On(LED1);
    	            	 	 HAL_Delay(delay_high);
    	            	 	 BSP_LED_Off(LED1);
    	            	 	 HAL_Delay(delay_high);
    	             }
    	             BSP_LED_Off(LED1);
   			}

    	 }
    }
