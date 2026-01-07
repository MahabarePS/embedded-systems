#include<xc.h>

#pragma config OSC = HS 
#pragma config WDT = OFF

#define LED LC0
#define SW B0

#define _XTAL_FREQ 8000000 //8Mhz

volatile uint8_t swEvent=0;

void __interrupt() swISR(void);

void __interrupt() swISR(void){
    if(INT0IF){
        INT0IF=0;
        swEvent++;
    }
}

void main(void){
    //1. Disable analog
    ADCON1=0x0f;
    //2. input/output
    TRISBbits.RB0=1;    //input SW
    TRISCbits.RC0=0;    //output LED
    
    INTCON=0x90;        //GIE=INT0IE=1
    INT0IF=0;           //flag 0
    
    while(1){
    if(swEvent==3){
        //for LED to blink 5 times
        for(int i=0;i<10;i++){
            LED=~LED;
            __delay_ms(300);
        }
        swEvent=0;
    }
    }
}