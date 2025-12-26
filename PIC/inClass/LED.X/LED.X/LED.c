#include <xc.h>
#pragma config OSC = HS 
#pragma config WDT = OFF         
     
#define LED_PIN RA0 
#define LED_PORT PORTB

void delay(void);

void main(void) 
{
    TRISA0=0;
    TRISB=0xFF;   
    ADCON1=0x0f;
    nRBPU=0;
   
    while(1)
    {
       LED_PIN = ~LED_PIN;  
       LED_PORT = ~LED_PORT; 
       delay();
    }

    
         
}

void delay(void)
{
    unsigned int i=0,j=0;
    
    for(i=0;i<500;i++) 
      for(j=0;j<1000;j++);
}

