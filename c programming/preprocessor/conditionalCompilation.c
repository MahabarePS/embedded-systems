/*
 * author Prasad Mahabare
 * created on 28-12-2025-15h-23m
 * github: https://github.com/MahabarePS
 * copyright 2025
*/
/*
PS: Example demostrating preprocessor directive 
    - conditional compilation 1
*/
#include<stdio.h>
#define ALL_FUNCTIONS 0
int main(void){
    int a=0,b=0,r=0;
    printf("\nEnter two numbers: ");
    scanf("%d%d",&a,&b);
    r = a+b;
    printf("Addition of %d + %d = %d ",a,b,r);
    r = a-b;
    printf("Subtraction of %d - %d = %d ",a,b,r);
    #if ALL_FUNCTIONS==1
        r = a*b;
        printf("\nMultiplication of %d * %d = %d", a,b,r);
        r = a/b;
        printf("\nDivision of %d / %d = %d",a,b,r);
    #endif
    return 0;
}