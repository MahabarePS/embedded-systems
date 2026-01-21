#include"LCD.h"
int main(void)
{
    INT0_init();
    TRISBbits.RB0 = 1;
    LCD_GPIO_Init();
    LCD_Init();
    LCD_StringDisplay(label);
    Timer1_init();
    uint32_t diff_ticks;
    uint32_t diff_ms;
    while (1){
        if (measurement_ready)
    {
        uint32_t diff_ticks;
        uint32_t diff_ms;
        unsigned char buf[16];

        diff_ticks = timestamp2 - timestamp1;
        diff_ms = (diff_ticks * 4) / 1000;   // 4 µs tick

        LCD_Command(0x01);                  // clear LCD
        __delay_ms(2);

        LCD_StringDisplay(label);
        u32_to_str(diff_ms, buf);
        LCD_StringDisplay(buf);

        measurement_ready = 0;
    }
    }
}