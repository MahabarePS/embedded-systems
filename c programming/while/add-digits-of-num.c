//Program to find addition of digitis of a given number
#include <stdio.h>
int main(){
    int n=0,r=0;
    printf("Enter a number : ");
    scanf("%d",&n);
    while(n!=0){
        r=r+(n%10); //getting last digit and adding to r
        n=n/10; //removing last digit from n
    }
    printf("\naddition of digits = %d",r);
    return 0;
}