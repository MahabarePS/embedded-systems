//Program to find factorial of a given number:
#include<stdio.h>
int main(){
    int i=0,n=0,r=1;
    printf("Enter a number: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        r=r*i;
    printf("\n%d",r);
}