#include<xc.h>

#include<xc.h>

#pragma config OSC = HS 
#pragma config WDT = OFF

#define LED LATCbits.LATC1
#define SWITCH PORTCbits.RC0

#define _XTAL_FREQ 8000000 //8Mhz

void main(void){
    //1. Disable analog
    ADCON1=0x0F;    //all digital
}