/*
 * author Prasad Mahabare
 * created on 10-03-2026-12h-34m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
#include<stdio.h>
#include<stdint.h>
int main(void){
    uint8_t x = 5;
    // pre-increment
    uint8_t y = ++x;                        //incremented value needed immediately
    printf("x after pre-increment: %d",x);
    printf("\ny after pre-increment: %d",y);
    printf("\n----------------------------------");
    x=5;
    y=x++;                                  //class loop increment
    // post-increment
    printf("\nx after pre-increment: %d",x);
    printf("\ny after pre-increment: %d",y);

    return 0;
}