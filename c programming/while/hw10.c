//hw10: 10.	find the factorial of given number
#include<stdio.h>
int main(){
    int num=0,i=0,temp=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    i=(num-1);
    if(num==0)
    {
        num=1;      //0!=1
    }
    while(i>0){
        num = num *i;
        i--;
    }
    printf("factorial is: %d",num);
}