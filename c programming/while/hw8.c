//hw8: Check whether the given number is prime
/*
The number which is for example:
2 mod 1 = 0
2 mod 2 = 0
*/
#include<stdio.h>
int main(){
    int n=0,temp=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    if(n<=1){
        printf("Not a prime");
        return 0;
    }
    int i=2;
    while(i<n){
        if(n%i==0){
            temp=1;
            break;
        } i++;
    }
    if(temp==0)
        printf("prime");
    else
        printf("not prime");
}