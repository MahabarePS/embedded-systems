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
    
#define DEBOUNCE_TICKS 5000 // 20ms / 4us
 
unsigned char count='\0';
unsigned char label[]="Time(ms):";

volatile uint8_t measurement_ready=0,press_state=0;
volatile uint16_t stamp2=0,stamp1=0, overflow_count=0;
volatile uint32_t timestamp1=0,timestamp2=0, timeDiff=0, last_accepted_timestamp=0;


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
void u32_to_str(uint32_t value, unsigned char *str)
{
    uint8_t i = 0;
    unsigned char temp[16];

    if (value == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }

    while (value > 0) {
        temp[i++] = (value % 10) + '0';
        value /= 10;
    }

    for (uint8_t j = 0; j < i; j++)
        str[j] = temp[i - j - 1];

    str[i] = '\0';
}


void INT0_init(void)
{
    ADCON1 = 0x0F;                  // all digital
    TRISBbits.TRISB0 = 1;           // RB0 input

    INTEDG0 = 0;                    // falling edge (pull-up + button to GND)
    INT0IF = 0;                     // clear flag
    INT0IE = 1;                     // enable INT0
}

void Timer1_init(void)
{
    T1CON = 0;
    T1CONbits.TMR1CS   = 0;          // Fosc/4
    T1CONbits.T1CKPS = 0b11;         // 1:8 prescaler
    T1CONbits.TMR1ON = 1;            // start timer

    TMR1IF = 0;
    TMR1IE = 1;                      // enable Timer1 overflow interrupt
}

void __interrupt() ISR(void)
{
    /* -------- Timer1 overflow -------- */
    if (TMR1IF)
    {
        TMR1IF = 0;
        overflow_count++;
    }

    /* -------- INT0 button event -------- */
    if (INT0IF)
    {
        uint8_t h, l;
        uint16_t tmr;
        uint32_t timestamp;

        INT0IF = 0;

        /* atomic read of Timer1 */
        h = TMR1H;
        l = TMR1L;
        tmr = ((uint16_t)h << 8) | l;

        timestamp = ((uint32_t)overflow_count << 16) | tmr;

        /* ---- debounce gate ---- */
        if (timestamp - last_accepted_timestamp < DEBOUNCE_TICKS)
            return;   // bounce ? ignore

        last_accepted_timestamp = timestamp;

        /* ---- state machine ---- */
        if (press_state == 0)
        {
            timestamp1 = timestamp;
            press_state = 1;
        }
        else
        {
            timestamp2 = timestamp;
            measurement_ready = 1;
            press_state = 0;
        }
    }
}



#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */
