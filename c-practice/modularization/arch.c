/*
 * author Prasad Mahabare
 * created on 19-02-2026-22h-20m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
Here is the purely abstract system:

Every 20ms:

Get a raw input value (integer)
Transform it into another value
Decide a level (LOW, MEDIUM, HIGH)
Apply the level

Imagine:

Input:  123
Transform → 456
Decision → MEDIUM
Apply → Some output

You are only designing the flow structure.

Design:

get_input()
transform()
decide_level()
apply_action()

With:

Proper return types
Proper parameters
No unnecessary pointers

Clean main()
*/
#include<stdio.h>
#include<stdint.h>

int main(void){
    while(1){
        decide_level();
    }
    return 0;
}
void decide_level(){
    uint16_t level = transform();
    if(level <50){
        apply_action();
    }
    else{
        return;
    }
}
uint16_t transform(){
    uint16_t input = get_input();
    // add 3 to each digit of input
    return; //transformed level

}
uint16_t get_input(){
    //get some input
}
