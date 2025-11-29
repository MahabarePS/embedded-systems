/*
hw8: WAP to set 28th bit of integer variable without
     affecting other bits
*/
#include<stdio.h>
int main(void){
    unsigned int num = 47;
    printf("before  : %x",num);
    num |= (1U<<28); //28th bit 0 to 1
    printf("\nafter : %x",num);
    return 0;
}