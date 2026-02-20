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
typedef enum{
    LOW = 5,
    MEDIUM = 25,
    High = 35
}Threshold;
int main(void){
    while(1){
        uint16_t temp = read_temp();
        uint16_t filter = temp_filter(temp);
        Threshold level = check_threshold(filter);
        trigger_alarm(level);
    }
    return 0;
}