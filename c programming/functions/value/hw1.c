/*
hw1: WAP to to addition of 3 numbers 
     and display the addition in called function.
*/
#include<stdio.h>
//function declare
int add(int, int);
int main(void){
    int num1=0,num2=0,sum=0;
    printf("enter two numbers");
    scanf("%d%d",&num1,&num2);
    //function call with actual arguments
    sum = add(num1,num2);
    printf("addition: %d",sum);
    return 0;
}
//function add with num1 | num2 formal arg
int add(int num1,int num2){
    int z = 0;
    z = num1+num2;
    return z;
}