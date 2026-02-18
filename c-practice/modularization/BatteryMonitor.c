/*
 * author Prasad Mahabare
 * created on 18-02-2026-10h-35m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
Industry Scenario 1: Battery Monitoring 
You are designing a firmware for a portable IoT device.
Requirement:
- ADC gives raw 12-bit value (0-4095)
- Convert it to milivolts (0-3300mV)
- Main loop stores result in a variable
Task:
Design the function prototype for:
- Reading ADC
- Converting ADC to milivolts
*/
#include<stdio.h>
#include<stdint.h>
uint16_t read_adc(void); //reads the adc
uint16_t adc_to_mV(uint16_t);//to convert you need adc value
int main(void){
    uint16_t adc_val = read_adc();
    uint16_t voltage = adc_to_mV(adc_val);
    return 0;
}
uint16_t read_adc(){
    return 0;
}
uint16_t adc_to_mV(uint16_t adc_val){
    return 0;
}