#include"LCD.h"
unsigned char count='\0';
unsigned char label[]="COUNT:";
volatile uint8_t pressCount=0;
int main(void)
{
    ADCON1 = 0x0F;
    TRISBbits.RB0 = 1;

    LCD_GPIO_Init();
    LCD_Init();
    LCD_StringDisplay("COUNT:");
    
    T0CON = 0x07;   // OFF, 16-bit, prescaler 1:256
    TMR0H = 0x67;
    TMR0L = 0x69;

    TMR0IF = 0;
    TMR0IE = 1;
    INT0IF = 0;
    INT0IE = 1;
    GIE = 1;

    TMR0ON = 1;

    while (1)
    {
        if(SW==0){          //when pressed
            __delay_ms(20);     
            while(SW==0);   //wait for release
            __delay_ms(20);
            pressCount++;
            if(TMR0IF){
                TMR0IF = 0;

                // reload 5s
                TMR0H = 0x67;
                TMR0L = 0x69;

                cycle++;
                if (cycle >= 2)   // 2 × 5s = 10s
                {
                    LCD_Init();
                    LCD_StringDisplay("COUNT:");
                    LCD_swCount(pressCount);
                }
            }
        
    }
}
}