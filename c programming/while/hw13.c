/*
hw13: Write a program to convert give number into binary and display it
*/
#include<stdio.h>
int main(){
    int bin[16]={0},temp=0,num=0,i=0;
    printf("enter the integer to convert: ");
    scanf("%d",&num);
    temp = num;
    while(num>0){
        bin[i]= num %2;
        num = num / 2;
        i++;
    }
    printf("Binary of %d is: ", temp);
    while(i>=0){
        printf("%d\t",bin[i]);
        i--;
    }
}