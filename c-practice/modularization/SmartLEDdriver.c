/*
 * author Prasad Mahabare
 * created on 18-02-2026-11h-05m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*

Industry Scenario 3: Smart LED Driver
Device must:

Read ambient light sensor (ADC)
Convert ADC to lux
Decide brightness level (Low / Medium / High)
Update PWM duty cycle
Run every 20ms

Constraints:

Clean architecture
Scalable (future auto-dimming curve may change)
Easy to debug
No unnecessary globals
Your Task

Design:

Clean modular function prototypes
No implementations
Think ownership
Think const correctness
Think data flow

Goal:

Your main() loop should look clean and readable.

*/
#include<stdio.h>
#include<stdint.h>
uint16_t read_light_adc();
uint16_t adc_to_volts(uint16_t*);
uint8_t volts_to_lux(uint16_t*);
void LED_brightness();
int main(void){
    while(1){
        LED_brightness();
    }
    return 0;
}
void LED_brightness(){
    uint16_t adc = read_light_adc();
    uint16_t voltage = adc_to_volts(&adc);
    uint8_t lux = volts_to_lux(voltage);
    enum PWM {
        LOW = 33,
        MEDIUM = 66,
        HIGH = 99
    };
    if(lux<100){
        new_pwm(HIGH);
    }else if(lux<500){
        new_pwm(MEDIUM);
    }else{
        new_pwm(LOW);
    }
}
void new_pwm(){

}
