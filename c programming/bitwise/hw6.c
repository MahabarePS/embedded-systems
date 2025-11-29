/*
hw6: WAP to  unpack nibbles of character variable c, 
     store lower nibble of c at lower nibble of character variable
     d & higher nibble of c at lower nibble of character 
     variable e (***variable c & higher nibble of variable 
     d & e should be unaffected)
*/
#include<stdio.h>
int main(void){
    unsigned char c = 0x27; // 0010 0111
    unsigned char d = 0xdd; // 1011 1011
    unsigned char e = 0x7d; // 0111 1011
    //lower nibble of c to lower nibble of d
    d = (c & 0x0f) | (d & 0xf0);            // 1011 0111 = d7
    printf("d after: %x",d);
    //higher nibble of c to lower nibble of e
    e = ((c & 0xf0)>>4)| ((e & 0xf0));        // 0111 0010 = 72
    printf("\ne after: %x",e);
    return 0;
}