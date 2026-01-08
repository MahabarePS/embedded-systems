/* 
 * File:   LCD.h
 * Author: Prasad Mahabare
 *
 * Created on 7 January, 2026, 6:38 PM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include<stdio.h>

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
    
#define SW PORTBbits.RB0

volatile uint8_t swEvent=0;
   

void LCD_GPIO_Init(void);
void LCD_Init(void);
void LCD_Command (unsigned char );
void LCD_Data (unsigned char );
void LCD_StringDisplay(unsigned char *);

void LCD_swCount(uint8_t count);
void __interrupt() swISR(void);


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
//counting the switch count
void LCD_swCount(uint8_t count){
    LCD_Data(count+'0');
    __delay_ms(2);
    //get the cursor back
    LCD_Command(0x10);
     __delay_ms(2);
}

void __interrupt() swISR(void){
    if(INT0IF){
        INT0IF=0;
        swEvent++;
    }
}

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */
