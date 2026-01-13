#include"LCD.h"
unsigned char count='\0';
unsigned char label[]="COUNT:";
int main(void)
{
    ADCON1 = 0x0F;
    TRISBbits.RB0 = 1;

    LCD_GPIO_Init();
    LCD_Init();
    LCD_StringDisplay("COUNT:");

    Timer0_Init();

    while (1)
    {
        if (display_10s)
        {
            display_10s = 0;

            LCD_Command(0x86);     // move cursor
            LCD_swCount(swEvent); // safe here
        }
    }
}
