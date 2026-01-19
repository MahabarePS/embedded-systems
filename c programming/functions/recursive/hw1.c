/*
hw1: WAP to print 1 to 100 using recurssive function
*/
#include<stdio.h>
int display(int);
int main(void){
    display(1);
    return 0;
}
// printing 1 to 100 recursively
int display(int x){
    if(x>100){
        return 0;
    }
    printf("%d\n",x);
    display(x+1);
}