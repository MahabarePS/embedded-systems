/*
hw3: WAP to compliment the 7th bit of character variable
     without affecting other bits
*/
#include<stdio.h>
int main(void){
    unsigned char ch = 0xd2;
    ch ^= (1<<7);               // ch = ch ^ 0x80;
    printf("After bit compliment of 0xd2: 0x%x",ch);
    return 0;
}