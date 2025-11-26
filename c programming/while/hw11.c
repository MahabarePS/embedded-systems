//hw11: print Fibonacci series
#include<stdio.h>
int main(){
    int num=0, i=0, j=1, count=0, next=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    printf("%d\t",i);   //f(0)=0
    printf("%d\t",j);   //f(1)=1
    while(count<(num-2)){   //skipping f(0) and f(1)
    next = j+i;
    count++;
    printf("%d\t",next);
    i=j;
    j=next;
    }
}
