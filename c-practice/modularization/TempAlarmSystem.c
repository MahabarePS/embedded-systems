/*
 * author Prasad Mahabare
 * created on 20-02-2026-22h-52m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*

System:

Reads temperature
Filters it (moving average)
Checks threshold
Triggers alarm if exceeded

Constraint:

Filter needs internal state (previous samples)
State must not be global

Task
Design:

Where should filter state live?
Should it be static?
Should caller pass buffer?
How should API look?

*/
#include<stdio.h>
#include<stdint.h>
typedef struct{
    uint16_t history[5];
    uint8_t index;
    uint32_t sum;
}MovingAverageFilter;
typedef enum{
    LOW = 5,
    MEDIUM = 25,
    HIGH = 35
}Threshold;
MovingAverageFilter temp_filter_instance;
int main(void){
    filter_init(&temp_filter_instance);
    while(1){
        uint16_t temp = read_temp();
        uint16_t filtered = filter_update(&temp_filter_instance, temp);
        Threshold level = check_threshold(filtered);
        trigger_alarm(level);
    }
    return 0;
}