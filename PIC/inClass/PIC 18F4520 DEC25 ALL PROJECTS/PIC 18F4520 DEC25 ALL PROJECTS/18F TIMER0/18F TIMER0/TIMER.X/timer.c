
#include <xc.h>
#pragma config OSC = HS
#pragma config WDT = OFF

#define LED RD0



void  __interrupt(high_priority)HIGH_ISR(void)
{
   if(TMR0IF==1)
  {
   
     LED=~LED;

     TMR0ON=0;
     TMR0H=0x3C;
     TMR0L=0xB0;
     TMR0ON=1;
     
     TMR0IF=0;
  }
}


void main(void)
{

ADCON1=0x0F;
TRISD0=0;

T0CON=0x00;
TMR0H=0x3C;
TMR0L=0xB0;


TMR0IF=0;
TMR0IE=1;
GIE=1;
TMR0ON=1;


while(1);
}