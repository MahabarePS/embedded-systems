/*
hw5: WAP to divide given number by 2
     without using arithmetic operators
*/
#include<stdio.h>
int main(void){
    unsigned int num = 0;
    printf("Enter an integer: ");
    scanf("%d",&num);
    num = (num>>1);
    printf("after divide by 2: %d", num);
    return 0;
}