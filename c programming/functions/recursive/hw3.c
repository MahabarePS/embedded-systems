/*
 * author Prasad Mahabare
 * created on 19-01-2026-11h-32m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
PS: WAP to display the addition of 1 to 10 using recursive funtion
*/
#include<stdio.h>
int sum(int);
int main(void){
    int num=0,result=0;
    result = sum(num);
    printf("Sum of 1 to 10: %d",result);
    return 0;
}
int sum(int x){
    //base case
    if(x>10){
        return 0;
    }
    return x + sum(x+1);
}