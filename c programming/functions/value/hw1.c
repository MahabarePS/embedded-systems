/*
hw1: WAP to to addition of 3 numbers 
     and display the addition in called function.
*/
#include<stdio.h>
int add(int, int, int);          //function declare
int main(void){
    int num1=0,num2=0, num3=0,sum=0;
    printf("enter three numbers");
    scanf("%d%d%d",&num1,&num2,&num3);
    //function call with actual arguments
    add(num1,num2,num3);
    return 0;
}
//function add with num1 | num2 formal arg
int add(int num1,int num2, int num3){
    int z = 0;
    z = num1+num2+num3;
    printf("addition: %d",z);
    return z;
}