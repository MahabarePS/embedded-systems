/*
hw1: WAP to print 1 to 100 using recurssive function
*/
#include<stdio.h>
int display(int);
int main(void){
    unsigned int num=1;
    display(num);
    return 0;
}
// printing 1 to 100 recursively
int display(int x){
    if(x<=100){
        printf("%d\t",x);
        x++;
    }
    display(x);
}