/*
hw1: Finding length of string
*/
#include<stdio.h>
int main(void){
    char str[50]={0};
    printf("Enter string: ");
    scanf("%[^\n]s",str);
    int index = 0;
    while(str[index]!='\0'){
        index++;
    }
    printf("\nLength of str: %d",index);
    return 0;
}