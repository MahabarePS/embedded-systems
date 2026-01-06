#include<xc.h>

#pragma config OSC = HS 
#pragma config WDT = OFF

#define LED LATCbits.LC0
#define SW PORTBbits.RB0

#define _XTAL_FREQ 8000000 //8Mhz

volatile uint8_t swEvent=0;
void __interrupt() swISR(void);

void __interrupt() swISR(void){
    if(INT0IF==1){
        while(INT0IF==0);
        swEvent++;
        INT0IF=0;
    }
}

void main(void){
    //1. Disable analog
    ADCON1=0x0f;
    //2. input/output
    TRISBbits.RB0=1;    //input SW
    TRISCbits.RC0=0;    //output LED
    //INTCON2bits.RBPU=0; // Enable pull-up
    //INTCON=0x90;      //GIE=INT0IE=1
    INTCONbits.INT0IF=0;//Initially flag 0
    INTCONbits.INT0IE=1;//External Interrupt Enable
    INTCONbits.GIE=1;   //Global Interrupt Enable
    
    while(1){
        if(swEvent==1){
            LED=1;
            __delay_ms(20);
            LED=0;
            __delay_ms(20);
        }
    }
}