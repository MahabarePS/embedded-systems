/*
hw14: Write a program to display ASCII table using only single variable
*/
#include<stdio.h>
int main(){
    char ch = '\0';
    while(ch>-128&&ch<128){
        printf("ASCII value of %c is: %d \n",ch,ch);
        ch++;
    }
    return 0;
}