/*
hw1: Write a program to scan and display integer using pointer
*/
#include<stdio.h>
int main(){
    int x = 0, *pt=&x;
    printf("enter a number: ");
    scanf("%d",pt);
    printf("%d",*pt);
}