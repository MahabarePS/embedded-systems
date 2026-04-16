/*
 * ledblink.c
 *
 *  Created on: Mar 16, 2024
 *      Author: DELL
 */
#include "stm32f4xx_hal.h"
#include "ledblink.h"

void pc10_led_init(void)
{
	GPIO_InitTypeDef 	GPIO_InitStruct ={0};
	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitStruct.Pin   = LED_PIN;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull  =  GPIO_NOPULL;
	GPIO_InitStruct.Speed =  GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init (GPIOC, &GPIO_InitStruct);

}


void Led_Blink(void *pvParameters)
{
  pc10_led_init();

  while(1)
  {

	  HAL_GPIO_WritePin(LED_PORT,LED_PIN, GPIO_PIN_SET);
	  HAL_Delay(1000);

	  HAL_GPIO_WritePin(LED_PORT,LED_PIN,GPIO_PIN_RESET);
	  HAL_Delay(1000);

  }
}
