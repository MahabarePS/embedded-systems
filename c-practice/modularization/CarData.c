/*
 * author Prasad Mahabare
 * created on 21-02-2026-23h-20m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

uint16_t read_temperature(void);
bool is_overheat(uint16_t temperature);
void set_fan(bool state);

int main(void){
    uint16_t temp = read_temperature();
    bool overheat = is_overheat(temp);
    set_fan(overheat);
}