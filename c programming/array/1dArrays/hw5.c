/*
 * author Prasad Mahabare
 * created on 02-01-2026-12h-25m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
PS: Given an integer, how many 1 bits are preset in its binary form
*/
#include<stdio.h>
int main(void){
    //get an integer
    int num,isNegative=0,i=0;
    char str[20];
    printf("Enter an integer: ");
    scanf("%d",&num);
    //check if it is zero
    if(num==0){
        str[i++]='0';
    }
    //check if it is negative number
    if(num<0){
        isNegative=1;
        num=-num;
    }
    
    return 0;
}