#include"LCD.h"
unsigned char count='\0';
unsigned char label[]="COUNT:";
int main(void)
{
  TRISBbits.RB0=1;  // input switch
  //Timer configs
  T1CON=0xB4;       // RD16=T1CKPS1=T1CKPS0=nT1SYNC=1
  //For exteranl interrupt
  INTCON=0x90;      // GIE=INT0IE=1
  INT0IF=0;
  ADCON1=0x0F;
  //LCD config
  LCD_GPIO_Init();
  LCD_Init();
  LCD_StringDisplay(label);  
  while(1){
    if(swEvent){
        LCD_swCount(swEvent);
    }
    }
}