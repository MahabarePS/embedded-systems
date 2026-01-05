#include<xc.h>

#pragma config OSC = HS 
#pragma config WDT = OFF

#define LED LATCbits.LATC1
#define SWITCH PORTCbits.RC0

#define _XTAL_FREQ 8000000 //8Mhz

void main(void){
    //1. Disable analog
    ADCON1=0x0F;    //all digital
    //2. Set direction
    TRISCbits.RC0=1;//Switch (input)
    TRISCbits.RC1=0;//LED    (output)
    //3. Initialize output
    LED=0;
    uint8_t pressCount=0;
    while(1)
    {
        
            while(SWITCH==0);
            __delay_ms(20);
            pressCount++;
            if(pressCount==3){
                LED=1;
                __delay_ms(20);
                LED=0;
                __delay_ms(20);
                LED=1;
                __delay_ms(20);
                LED=0;
                __delay_ms(20);
                pressCount=0;
            }
        
    }
}