#include "stm32f4xx_hal.h"

#define D0_Pin GPIO_PIN_0
#define D1_Pin GPIO_PIN_1
#define D2_Pin GPIO_PIN_2
#define D3_Pin GPIO_PIN_3
#define D4_Pin GPIO_PIN_4
#define D5_Pin GPIO_PIN_5
#define D6_Pin GPIO_PIN_6
#define D7_Pin GPIO_PIN_7

#define RS_Pin GPIO_PIN_8
#define EN_Pin GPIO_PIN_9

#define LCD_PORT GPIOC


void LCD_GPIO_Init(void);
void LCD_Init(void);
void LCD_Command (unsigned char );
void LCD_Data (unsigned char );
void LCD_StringDisplay(char *);
