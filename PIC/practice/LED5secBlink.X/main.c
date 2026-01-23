#include <pic18f4520.h>

#include "TMR0.h"
int main(void)
{
    ADCON1 = 0x0F;
    TRISAbits.RA0 = OUTPUT_PIN;
    
    Timer0_init();
    static uint16_t onTime =0,offtime=0;
    static uint8_t ledstate = 0;
    
    while (1){
        if (!ledstate && msTick>=5000)   // 5sec
                {
                    LED=ON;
                    ledstate=1;
                    onTime = msTick;
                }
        if(ledstate &&(msTick-onTime)>=75){
            LED = OFF;
            ledstate=0;
            msTick=0;
        }
    }

}