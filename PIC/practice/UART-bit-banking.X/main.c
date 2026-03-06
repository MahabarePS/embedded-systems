/*
 * File:   main.c
 * Author: Prasad Mahabare
 *
 * Created on 5 March, 2026, 5:39 PM
 */
#include <xc.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#define _XTAL_FREQ 20000000


#define TX_PIN LATBbits.LATB0
#define TX_TRIS TRISBbits.TRISB0

// ---------------------------
// UART Frame using Bit-Field
// ---------------------------
typedef union {
    unsigned int frame;
    struct {
        unsigned start :1;
        unsigned d0 :1;
        unsigned d1 :1;
        unsigned d2 :1;
        unsigned d3 :1;
        unsigned d4 :1;
        unsigned d5 :1;
        unsigned d6 :1;
        unsigned d7 :1;
        unsigned stop :1;
    };
} UART_Frame;

volatile UART_Frame txframe;
volatile unsigned char bit_index = 0;

// ---------------------------------------
// Create a 10-bit UART frame from 8-bit data
// ---------------------------------------
void MakeFrame(unsigned char data)
{
    txframe.start = 0;     // Start bit
    txframe.stop = 1;      // Stop bit

    txframe.d0 = (data >> 0) & 1;
    txframe.d1 = (data >> 1) & 1;
    txframe.d2 = (data >> 2) & 1;
    txframe.d3 = (data >> 3) & 1;
    txframe.d4 = (data >> 4) & 1;
    txframe.d5 = (data >> 5) & 1;
    txframe.d6 = (data >> 6) & 1;
    txframe.d7 = (data >> 7) & 1;
}

// -----------------------------------------------------
// Start sending a byte manually using timer interrupts
// -----------------------------------------------------
void SendByte_Manual(unsigned char b)
{
    MakeFrame(b);
    bit_index = 0;

    TMR2 = 0;
    TMR2IF = 0;
    TMR2IE = 1;
}

// ------------------------------------------------------
// Timer2 ISR ? sends one bit every 104us (9600 baud)
// ------------------------------------------------------
void __interrupt(high_priority) ISR()
{
    if (TMR2IF)
    {
        TMR2IF = 0;

        if (bit_index < 10)
        {
            TX_PIN = (txframe.frame >> bit_index) & 1;
            bit_index++;
        }
        else
        {
            TMR2IE = 0;  
            TX_PIN = 1;  // Idle line
        }
    }
}

// ---------------------------
// Initialize Manual UART TX
// ---------------------------
void BitBangUART_Init()
{
    TX_TRIS = 0;
    TX_PIN = 1;  // Idle state (High)

    
    T2CON = 0x04;  // Prescaler 1:1 (or use 16 if needed)
    PR2 = 156;     // Adjust for perfect baud rate (fine tuned)

    TMR2ON = 1;
    PEIE = 1;
    GIE = 1;
}

// ---------------------------
// Send string using manual TX
// ---------------------------
void UART_WriteString(const char *s)
{
    while(*s)
    {
        SendByte_Manual(*s++);  
        __delay_ms(2);          
    }
}

// ---------------------------
// MAIN PROGRAM
// ---------------------------
void main(void)
{
    BitBangUART_Init();

    while(1)
    {
        UART_WriteString("HELLO VAISHALI\r\n");
        __delay_ms(1000);
    }
}