/*
 * author Prasad Mahabare
 * created on 22-01-2026-23h-04m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
PS: Write a program to accept a number and print 
    week day accordingly (Monday for 1, Tuesday for 2, 
    Wednesday for 3……..Sunday for 7)
*/
#include<stdio.h>
int main(void){
    unsigned int day=0;
    do{
    printf("------------Day of the Week------------\n");
    printf("Choose from: 1-2-3-4-5-6-7\n");
    printf("Enter a day: ");
    scanf("%d",&day);
    switch(day){
        case 1: printf("Monday!\n");
                break;
        case 2: printf("Tuesday!\n");
                break;
        case 3: printf("Wednesday!\n");
                break;
        case 4: printf("Thursday!\n");
                break;
        case 5: printf("Friday!\n");
                break;
        case 6: printf("Saturday!\n");
                break;
        case 7: printf("Sunday!\n");
                break;
        default: printf("Enter the valid day!\n");
                break;
        }
    }while(day<8);
    return 0;
}