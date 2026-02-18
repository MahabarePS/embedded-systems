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

uint16_t read_light_adc(void);
uint16_t adc_to_lux(uint16_t);
uint8_t decide_brightness(uint16_t);
void pwm_set_duty(uint8_t duty);
void led_update();

typedef enum{
    PWM_LOW = 33,
    PWM_MEDIUM = 66,
    PWM_HIGH = 99
}PWM_Level;

int main(void){
    while(1){
        led_update();
    }
    return 0;
}
void led_update(void){
    uint16_t adc = read_light_adc();
    uint16_t lux = adc_to_lux(adc);

    PWM_Level level = decide_brightness(lux);

    pwm_set_duty(level);
}