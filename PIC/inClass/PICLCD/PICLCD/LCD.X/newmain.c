#include <xc.h>

#pragma config OSC = HS 
#pragma config WDT = OFF          

#define _XTAL_FREQ 8000000

#define LCD_PORT PORTD
#define LCD_RS RA0
#define LCD_RW RA1
#define LCD_EN RA2

#define LCD_PORT_CONFIG TRISD
#define RS_CONFIG TRISA0 
#define RW_CONFIG TRISA1
#define EN_CONFIG TRISA2

#define OUTPUT_PIN 0
#define INPUT_PIN 1
#define OUTPUT_PORT 0x00
#define INPUT_PORT 0xff



void LCD_GPIO_Init(void);
void LCD_Init(void);
void LCD_Command (unsigned char );
void LCD_Data (unsigned char );
void LCD_StringDisplay(unsigned char *);



unsigned char MSG1[] = "BICARD";
unsigned char MSG2[] = " PIC CONTROLLER";



int main(void)
{

   ADCON1=0x0F;
  LCD_GPIO_Init();
  LCD_Init();
  LCD_StringDisplay(MSG1);]
  LCD_Command(0xC0);
  LCD_StringDisplay(MSG2);

  while (1);
 

}


void LCD_GPIO_Init(void)
{
   LCD_PORT_CONFIG = OUTPUT_PORT;
   RS_CONFIG=OUTPUT_PIN;
   RW_CONFIG=OUTPUT_PIN;
   EN_CONFIG=OUTPUT_PIN;

}


void LCD_Init(void)
{
     LCD_Command(0x38);
     __delay_ms(2);
     LCD_Command(0x0E);
     __delay_ms(2);
     LCD_Command(0x06);
     __delay_ms(2);
     LCD_Command(0x01);
     __delay_ms(2);
}

void LCD_Command (unsigned char CMD)
{
      LCD_RW=0;
      LCD_RS=0;
      LCD_PORT=CMD;
      LCD_EN=1;
      __delay_us(10);
      LCD_EN=0;
}

void LCD_Data (unsigned char DAT)
{
      LCD_RW=0;
      LCD_RS=1;
      LCD_PORT=DAT;
      LCD_EN=1;
      __delay_us(10);
      LCD_EN=0;
}

void LCD_StringDisplay(unsigned char *str)
{
	while(*str!='\0')
	{
		LCD_Data(*str++);
		__delay_ms(2);
	}
}


