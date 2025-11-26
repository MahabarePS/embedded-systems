/*
hw2: WAP to set 2nd bit of an character variable 
     without affecting other bits
*/
#include<stdio.h>
int main(void){
    unsigned char ch = 0x52;
    ch = ch | 0x04;
    printf("After setting 2nd bit of 0x50: 0x%x",ch);
    return 0;
}