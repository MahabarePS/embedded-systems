/*
hw4: WAP to multiply given number by 4 
     without using arithmetic operators
*/
#include<stdio.h>
int main(void){
    unsigned int i = 5;
    i |= (i<<4);
    printf("%d",i);
    return 0;
}