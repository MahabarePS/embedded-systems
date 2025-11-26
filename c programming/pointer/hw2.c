/*
hw2: Write a program to scan and display
     character using pointer
*/
#include<stdio.h>
int main(){
    char str='\0', *pt = &str;
    printf("enter a char: ");
    scanf(" %c",pt);
    printf("char is: %c",*pt);
}