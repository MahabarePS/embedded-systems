#include <pic18f4520.h> 
#include "TMR0.h" 
int main(void) { 
    
    ADCON1 = 0x0F; 
    TRISAbits.RA0 = OUTPUT_PIN; 
    Timer0_init(); 
    LED=OFF;
    while (1)
    { 
        if (cycle)
        {
            LED = !LED;
            __delay_ms(75);
            LED = !LED;     
            cycle = 0;
        }
    } 
}