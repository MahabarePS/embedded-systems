/*
 * author Prasad Mahabare
 * created on 19-01-2026-20h-51m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
PS: Write a program to accept a number from user in main function,
    find its factorial using recursive function & display the result
    in the main function.
*/
#include<stdio.h>
int factorial(int);
int main(void){
    int num=0, fact=0;
    printf("Enter an integer for factorial: ");
    scanf("%d",&num);
    fact = factorial(num);
    printf("Factorial of %d is: %d",num,fact);
    return 0;
}
int factorial(int x){
    if(x<=0){
        return 1;
    }
    if(x>=1){
    return x*factorial(x-1);
    }
}