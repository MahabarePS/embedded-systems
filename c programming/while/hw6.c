//hw6: Display the addition of digits of a given number
#include<stdio.h>
int main(){
    int i=0,r=0,num=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    while(num!=0){
        r = r +(num%10);
        num = num/10;
    }
    printf("addition of the digits: %d", r);
}