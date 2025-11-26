//hw5: Find square of a given number without using * operator
#include<stdio.h>
int main(){
    int m=0,i=1,sum=0;
    printf("Enter a number: ");
    scanf("%d",&m);
    while(i<=m){
        sum = sum + m;
        i++;
    }
    printf("Square of a given number is: %d",sum);
}