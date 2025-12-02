/*
hw2: WAP to do addition of 3 numbers & display the addition
     in main function.
*/
#include<stdio.h>
int add(int, int, int);     //function declaration
int main(void){
    // initialize three variables to store user i/p
    int num1=0,num2=0,num3=0,sum=0;
    printf("Enter three integers: ");
    scanf("%d%d%d",&num1,&num2,&num3);
    // pass those actual parameters to add function and store the
    // result in a sum variable
    sum = add(num1,num2,num3);
    // print the sum of integers
    printf("\nAddition is: %d",sum);
    return 0;
}

int add(int x ,int y,int z){
    int w = x+y+z;
    return w;
}