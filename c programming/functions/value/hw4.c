/*
hw4: WAP to find whether the given number is prime or not,
     display the result message in called function.
*/
#include<stdio.h>
int isPrime(int);
int main(void){
    int num = 0;
    printf("Enter an integer: ");
    scanf("%d",&num);
    isPrime(num);
    return 0;
}
int isPrime(int x){
    int i = 1, flag =0;
    int num = x;
    if(num==1){
        return printf("Entered Integer is not prime");
    }
    else{
    while(i*i<=num){
        if(num%i==0){
            flag++;
        }
        i++;
    }
    }      
    if(flag>2){
        return printf("Entered Integer is not prime");
    }
    else{
        return printf("Entered Integer is prime");
    }
}