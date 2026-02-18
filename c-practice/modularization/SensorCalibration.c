/*
 * author Prasad Mahabare
 * created on 18-02-2026-10h-54m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
Industry Scenario 2: Sensor Calibration
You receive raw temperature value from ADC
Before using it, you must:
- Apply offest correction
- Apply gain correction
- Clamp it between min and max range
corrected = (raw + offset) * gain
Correction modifies the original value.
System constraints:
- Runs every 10ms
- Must be efficient
- Value must be modified
- Calibration parameters may change later 
design question is:
* Who owns the temperature value?
* Should the function modify it directly?
* Or return a new value?
Task:
Write a function prototype for:
apply_calibration(??)
*/
#include<stdio.h>
#include<stdint.h>
typedef struct{
    int16_t offset;
    float gain;
    int16_t min;
    int16_t max;
}Calibration;
int main(void){
    uint16_t adc_raw = 0;
    //
    Calibration cal = {
        .offset = -5,
        .gain = 1.1f,
        .min = 0,
        .max = 150
    };
    apply_calibration(&adc_raw,&cal);
    return 0;
}
void apply_calibration(uint16_t *raw, const Calibration *calib){
    int32_t temp;

    //(raw + offset)
    temp = *raw + calib->offset;
    //() * gain
    temp = temp * calib->gain;
    //clamp between min and max
    if(temp > calib->max){
        temp = calib->max;
    }else if(temp < calib->min){
        temp = calib->min;
    }
    *raw = (int16_t)temp;
}