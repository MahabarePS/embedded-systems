/*
hw4: WAP to multiply given number by 4 
     without using arithmetic operators
*/
#include<stdio.h>
int main(void){
    unsigned int i = 10;
    i = (i<<2);
    printf("after: %d",i);
    return 0;
}