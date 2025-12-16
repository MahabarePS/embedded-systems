/*
hw2: WAP to print 100 to 1 using recurssive function
*/
#include<stdio.h>
int display(int);
int main(void){
    unsigned int num=100;
    display(num);
    return 0;
}
// printing 1 to 100 recursively
int display(int x){
    if(x>=1){
        printf("%d\t",x);
        x--;
    }
    display(x);
}