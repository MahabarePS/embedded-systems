#include "stm32f4xx_hal.h"
#include <stdio.h>

//printf defination

//declare peripheral handle
TIM_HandleTypeDef hTim7;
ADC_HandleTypeDef hAdc1;
UART_HandleTypeDef hUart2;

void tim7_init(void);
void adc_init_conv_init(void);
void uart_init(void);


uint32_t sensor_value;

int main(void){
	HAL_Init();
	tim7_init();
	uart_init();
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
	  if( HAL_ADC_PollForConversion(&hadc1,1) )
	  {
		  // business logic
	  }
	  else
	  {
	     sensor_value =  pa1_adc_read();
	   	 HAL_Delay(10);
	   	 HAL_UART_Transmit(&huart2, sensor_value,sizeOf(sensor_value),1);
	   	 HAL_Delay(10);
	  }
  }
}
//ADC
void adc_init_conv_init(void){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	ADC_ChannelConfTypeDef sConfig = {0};


	    __HAL_RCC_GPIOA_CLK_ENABLE();

	    GPIO_InitStruct.Pin = GPIO_PIN_1;
	    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


	    __HAL_RCC_ADC1_CLK_ENABLE();

	    hAdc1.Instance = ADC1;
	    hAdc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	    hAdc1.Init.Resolution = ADC_RESOLUTION_12B;
	    hAdc1.Init.ContinuousConvMode = DISABLE;
	    hAdc1.Init.DiscontinuousConvMode = DISABLE;
	    hAdc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	    hAdc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	    hAdc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	    hAdc1.Init.NbrOfConversion = 1;
	    hAdc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;

	    HAL_ADC_Init(&hadc1);

	    sConfig.Channel =  ADC_CHANNEL_1;
	    sConfig.Rank = 1;
	    sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;

	    HAL_ADC_ConfigChannel(&hAdc1, &sConfig);

}
//UART
void uart_init(void){
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	   __HAL_RCC_USART2_CLK_ENABLE();
	   __HAL_RCC_GPIOA_CLK_ENABLE();


		GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	    hUart2.Instance = USART2;
	    hUart2.Init.BaudRate = 9600;
	    hUart2.Init.WordLength = UART_WORDLENGTH_8B;
	    hUart2.Init.StopBits = UART_STOPBITS_1;
	    hUart2.Init.Parity = UART_PARITY_NONE;
	    hUart2.Init.Mode = UART_MODE_TX_RX;
	    hUart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	    hUart2.Init.OverSampling = UART_OVERSAMPLING_16;
	    if (HAL_UART_Init(&hUart2) != HAL_OK)
	    {
	       // BUSINESS LOGIC
	    }
}
