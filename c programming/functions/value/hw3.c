/*
hw3: WAP to find the factorial of a given number, display the
     result in called function.
*/
#include<stdio.h>
int factorial(int);
int main(void){
    int num =0;
    printf("Enter an integer: ");
    scanf("%d",&num);
    factorial(num);
    return 0;
}
int factorial(int num){
    int i = num, fact =1;
    while(i>0){
        fact = fact * i;
        i -=1 ;
    }
    printf("Factorial of %d is: %d",num,fact);
}