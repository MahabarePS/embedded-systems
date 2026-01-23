#include <pic18f4520.h>

#include "TMR0.h"
int main(void)
{
    ADCON1 = 0x0F;
    TRISAbits.RA0 = OUTPUT_PIN;
    LED=OFF;
    
    Timer0_init();
    static uint16_t lastBlink =0,ledOnTime=0;
    static uint8_t ledState = 0;
    
    while (1){
        if (!ledState && (msTick>=BLINK_PERIOD))   // 5sec
                {
                    LED=ON;
                    ledState=1;
                    ledOnTime = msTick;
                    lastBlink = msTick;
                }
        if(ledState &&(msTick-ledOnTime>=PULSE_WIDTH)){
            LED = OFF;
            ledState=0;
        }
    }
}