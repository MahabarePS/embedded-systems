/*
hw1: WAP to reset the 4th bit of an character variable 
     without affecting other bits
*/
#include<stdio.h>
int main(void){
    unsigned char ch = 0xBC;
    ch &= ~(1 << 4);//0xEF;
    printf("After 4th bit reset of 0xBC: 0x%x",ch);
    return 0;
}