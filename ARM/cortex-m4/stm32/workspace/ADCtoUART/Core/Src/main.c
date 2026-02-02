
#include "stm32f4xx_hal.h"
#include "LCD.h"

uint32_t pa1_adc_read(void);
void adc_init_start(void);
void adc_pa1_single_conv_init(void);


ADC_HandleTypeDef hadc1;

uint32_t  sensor_value;


int main(void)
{
  char MSG1[] = "12 bit ADC";
  char str[20]={'\0'};

  HAL_Init();
  LCD_GPIO_Init();
  LCD_Init();
  LCD_StringDisplay(MSG1);

  adc_pa1_single_conv_init();


   HAL_Delay(10);

  while(1)
  {

	   HAL_ADC_Start(&hadc1);
	   if( HAL_ADC_PollForConversion(&hadc1,1) )
	   {
		   // business logic
	   }
	   else
	   {
        sensor_value =  pa1_adc_read();
 	    HAL_Delay(10);
 	    sprintf(str,"value = %lu",sensor_value);
 	    LCD_Command(0xC0);
 	    LCD_StringDisplay(str);

 	    HAL_Delay(10);
	   }

 	   HAL_Delay(1000);
  }
}

uint32_t pa1_adc_read(void)
{
	return HAL_ADC_GetValue(&hadc1);
}




void adc_pa1_single_conv_init(void)
{
	 GPIO_InitTypeDef GPIO_InitStruct = {0};
	 ADC_ChannelConfTypeDef sConfig = {0};


    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitStruct.Pin = GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);




    __HAL_RCC_ADC1_CLK_ENABLE();

    hadc1.Instance = ADC1;
    hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
    hadc1.Init.Resolution = ADC_RESOLUTION_12B;
    hadc1.Init.ContinuousConvMode = DISABLE;
    hadc1.Init.DiscontinuousConvMode = DISABLE;
    hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
    hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
    hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
    hadc1.Init.NbrOfConversion = 1;
    hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;

    HAL_ADC_Init(&hadc1);

    sConfig.Channel =  ADC_CHANNEL_1;
    sConfig.Rank = 1;
    sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;

    HAL_ADC_ConfigChannel(&hadc1, &sConfig);


}
