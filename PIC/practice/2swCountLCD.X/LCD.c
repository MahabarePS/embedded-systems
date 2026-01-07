#include"LCD.h"
volatile uint8_t swEvent=0;
unsigned char count='\0';
int main(void)
{
  TRISBbits.RB0=1; // input switch
  
  ADCON1=0x0F;
  LCD_GPIO_Init();
  LCD_Init();
  
//  LCD_Command(0xC0);
  while (1){
      if(SW==0){
          while(SW==0);
          swEvent++;
          LCD_swCount(swEvent);
      }
  }
  
}