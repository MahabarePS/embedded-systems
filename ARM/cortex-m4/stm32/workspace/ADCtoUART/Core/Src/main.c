#include "stm32f4xx_hal.h"
#include <stdio.h>

//printf defination

//declare peripheral handle
TIM_HandleTypeDef hTim7;
ADC_HandleTypeDef hAdc1;
UART_HandleTypeDef uart;

void tim7_init(void);
void adc_init_conv_init(void);
void uart_init(void);


uint32_t sensor_value;

int main(void){
	HAL_Init();
	tim7_init();
	while(1){

	}
}
//TIM7
void tim7_init(void){
	__HAL_RCC_TIM7_CLK_ENABLE();

	  hTim7.Instance       = TIM7;
	  hTim7.Init.Prescaler = 16000 - 1;
	  hTim7.Init.Period    = 1000 -1;
	  hTim7.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  hTim7.Init.CounterMode = TIM_COUNTERMODE_UP;
	  hTim7.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

	  //feedback mechanism for peripheral initialization
	  if (HAL_TIM_Base_Init(&hTim7) != HAL_OK)
	  {
	      printf("Error!");
	  }

	  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
	  HAL_NVIC_SetPriority(TIM7_IRQn, 0, 0);
	  HAL_NVIC_EnableIRQ(TIM7_IRQn);


	  /*Start the TIM Base generation in interrupt mode*/
	  HAL_TIM_Base_Start_IT(&hTim7);
}
void TIM7_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&hTim7);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(htim->Instance==TIM7)
  {
     //start ADC
	  HAL_ADC_Start_IT(&hAdc1);
  }
}
//ADC
void adc_init_conv_init(void){

}
//UART
void uart_init(void){

}
