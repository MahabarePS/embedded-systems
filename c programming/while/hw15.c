/*
hw15: Write a program to display alternate prime numbers
      up to the number given by user
*/
#include<stdio.h>
int main(){
    int num=0,limit=0,i=1,count=0;
    printf("Enter the limit: ");
    scanf("%d",&limit);
    num = limit; // keep the original limit value
    while(num>2){
        while(i<num){
            if(num/i==num)
            {   
                count++;
            }
            i++;
        }
        num--;
        if(count>1)
        { printf("%d\t",num);}
    }
}