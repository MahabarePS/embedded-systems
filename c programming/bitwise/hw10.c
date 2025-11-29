/*
hw10: WAP to copy bit no 3,4,5 from one character variable,
      to bit 5,6,7 respectively of another character variable 
*/
#include<stdio.h>
int main(void){
    unsigned char s = 0x2c;   
    unsigned char d = 0xe0;   
    d = ((s&0x38)<<2 | (d&0x1f));
    printf("after:  %x",d);  
    return 0;
}