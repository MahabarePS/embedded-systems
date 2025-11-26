/*
hw1: Write a program to scan & display 
     2d character array str[5][15]
*/
#include<stdio.h>
int main(){
    char str[5][15] = {0};
    int i=0;
    printf("enter 5 strings of size 15: \n");
    for(i=0;i<3;i++)
        scanf("%s",str[i]);

    for(i=0;i<3;i++)
        printf("%s\n",str[i]);
}