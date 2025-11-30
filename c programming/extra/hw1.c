/*
hw1: WAP to find number of words in the string entered by user
*/
#include<stdio.h>
int main(void){
    char str[50] = {0};
    int space = 0;
    printf("enter words: ");
    scanf("%s",str);
    
    printf("No. of words: %d",space+1);
    return 0;
}