#include "FreeRTOS.h"
#include "task.h"
#include "LCD.h"

void LCD_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};


  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();



  GPIO_InitStruct.Pin = D0_Pin|D1_Pin|D2_Pin|D3_Pin
                          |D4_Pin|D5_Pin|D6_Pin|D7_Pin
                          |RS_Pin|EN_Pin ;

  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LCD_PORT, &GPIO_InitStruct);

}


void LCD_Init(void)
{
	LCD_Command(0x38);
	HAL_Delay(20);
	LCD_Command(0x06);
	HAL_Delay(20);
	LCD_Command(0x0C);
	HAL_Delay(20);
	LCD_Command(0x01);
	HAL_Delay(20);
}

void LCD_Command (unsigned char CMD)
{
	HAL_GPIO_WritePin(LCD_PORT, RS_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_PORT, D0_Pin,(CMD & 0x01));
	HAL_GPIO_WritePin(LCD_PORT, D1_Pin,(CMD & 0x02)>>1);
	HAL_GPIO_WritePin(LCD_PORT, D2_Pin,(CMD & 0X04)>>2);
	HAL_GPIO_WritePin(LCD_PORT, D3_Pin,(CMD & 0X08)>>3);
	HAL_GPIO_WritePin(LCD_PORT, D4_Pin,(CMD & 0X10)>>4);
	HAL_GPIO_WritePin(LCD_PORT, D5_Pin,(CMD & 0X20)>>5);
	HAL_GPIO_WritePin(LCD_PORT, D6_Pin,(CMD & 0X40)>>6);
	HAL_GPIO_WritePin(LCD_PORT, D7_Pin,(CMD & 0X80)>>7);
	HAL_GPIO_WritePin(LCD_PORT, EN_Pin, GPIO_PIN_SET);
	HAL_Delay(3);
	HAL_GPIO_WritePin(LCD_PORT, EN_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
}

void LCD_Data (unsigned char DAT)
{
	HAL_GPIO_WritePin(LCD_PORT, RS_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_PORT, D0_Pin,(DAT & 0X01));
	HAL_GPIO_WritePin(LCD_PORT, D1_Pin,(DAT & 0X02)>>1);
	HAL_GPIO_WritePin(LCD_PORT, D2_Pin,(DAT & 0X04)>>2);
	HAL_GPIO_WritePin(LCD_PORT, D3_Pin,(DAT & 0X08)>>3);
	HAL_GPIO_WritePin(LCD_PORT, D4_Pin,(DAT & 0X10)>>4);
	HAL_GPIO_WritePin(LCD_PORT, D5_Pin,(DAT & 0X20)>>5);
	HAL_GPIO_WritePin(LCD_PORT, D6_Pin,(DAT & 0X40)>>6);
	HAL_GPIO_WritePin(LCD_PORT, D7_Pin,(DAT & 0X80)>>7);
	HAL_GPIO_WritePin(LCD_PORT, EN_Pin, GPIO_PIN_SET);
	HAL_Delay(3);
	HAL_GPIO_WritePin(LCD_PORT, EN_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
}

void LCD_StringDisplay(char *str)
{
	while(*str!='\0')
	{
		LCD_Data(*str++);
		HAL_Delay(2);
	}
}


void Lcd_display(void *pvParameters)
{
	int flag=1;
	LCD_GPIO_Init();
	LCD_Init();

  while(1)
  {

	  LCD_StringDisplay("Free RTOS");
	  HAL_Delay(1000);
	  if(flag==1)
	  {
		 LCD_Command (0x01);
	     LCD_Command (0xC0);
	     flag=0;
	  }
	  else
	  {
	  	 LCD_Command (0x01);
	  	 LCD_Command (0x80);
	  	 flag=1;
	  }
  }
}

