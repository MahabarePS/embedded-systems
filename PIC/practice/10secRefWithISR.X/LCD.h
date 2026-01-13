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

#define _XTAL_FREQ 20000000

#define LCD_PORT PORTD
#define LCD_RS RC1
#define LCD_RW RC0
#define LCD_EN RC2

#define LCD_PORT_CONFIG TRISD
#define RS_CONFIG TRISC1
#define RW_CONFIG TRISC0
#define EN_CONFIG TRISC2

#define OUTPUT_PIN 0
#define INPUT_PIN 1
#define OUTPUT_PORT 0x00
#define INPUT_PORT 0xff
    
#define SW PORTBbits.RB0

volatile uint8_t swEvent=0;
volatile unsigned char cycle = 0;
volatile unsigned char _10s_done=0;
volatile uint8_t display_10s = 0;
   

void LCD_GPIO_Init(void);
void LCD_Init(void);
void LCD_Command (unsigned char );
void LCD_Data (unsigned char );
void LCD_StringDisplay(unsigned char *);

void LCD_swCount(uint8_t count);

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
    uint8_t i=0,size=0,digit=0;
    unsigned char str[16];
    //extract the digit to char
    for(i=0;count>0;i++){
        size++;
        digit=count%10;
        str[i]=digit+'0';
        count = count/10;
    }
    str[size]='\0';
    uint8_t j=size-1;
    for(i=0;i<j;i++){
        uint8_t temp = str[i];
        str[i]=str[j];
        str[j]=temp;
        j--;
    }
    LCD_StringDisplay(str);
    __delay_ms(2);
    //get the cursor back
    LCD_Command(0x86);
     __delay_ms(2);
}

void Timer0_Init(void)
{
    T0CON = 0x07;   // OFF, 16-bit, prescaler 1:256
    TMR0H = 0x67;
    TMR0L = 0x69;

    TMR0IF = 0;
    TMR0IE = 1;
    INT0IF = 0;
    INT0IE = 1;
    GIE = 1;

    TMR0ON = 1;
}

void __interrupt() ISR(void)
{
    //---------- SWITCH INTERRUPT ----------
    if (INT0IF)
    {
        INT0IF = 0;
        swEvent++;
    }
    //---------- TIMER0 INTERRUPT ----------
    if (TMR0IF)
    {
        TMR0IF = 0;

        // reload 5s
        TMR0H = 0x67;
        TMR0L = 0x69;

        cycle++;
        if (cycle >= 2)   // 2 × 5s = 10s
        {
            cycle = 0;
            display_10s = 1;   // signal main loop
        }
    }
    
}



#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */
