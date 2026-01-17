#include"LCD.h"
unsigned char count='\0';
unsigned char label[]="COUNT:";
int main(void)
{
    ADCON1 = 0x0F;
    TRISBbits.RB4 = 1;
    
    LCD_GPIO_Init();
    LCD_Init();
    LCD_StringDisplay("COUNT:");
    Timer0_init();
    while (1)
    {
        if(SW==0){          //when pressed
                 
            while(SW==0);   //wait for release
            
            pressCount++;
    }
}
}