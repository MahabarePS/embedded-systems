/*
hw9: WAP to reset 3rd and 17th bit of int variable
     without affecting other bits
*/
#include<stdio.h>
int main(void){
    unsigned int num = 121;
    printf("before: %x",num);
    num &=~((1<<3)|(1<<17));
    printf("\nafter:   %x",num);
    return 0;
}