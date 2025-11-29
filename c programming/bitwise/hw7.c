/*
hw7: WAP to swap lower and upper nibble of 
     hex number stored in a character variable
*/
#include<stdio.h>
int main(void){
    unsigned char ch = 0x47;  //0100 0111
    printf("ch before: %x", ch);
    ch = ((ch&0x0f)<<4)|((ch&0xf0)>>4);
    printf("\nch after: %x", ch);
    return 0;
}