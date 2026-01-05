/*
 * author Prasad Mahabare
 * created on 05-01-2026-11h-43m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
PS: check whether the given number(3 digit) is Armstrong
*/
#include<stdio.h>
int main(void){
    //get number from user
    int num=0,sum=0,exponent=0,temp=0;
    int exp_result=0,digit=0,no_of_digits=0,count=0;
    printf("Enter an integer: ");
    scanf("%d",&num);
    //check for zero or -ve
    if(num<=0){
        return 1;
    }
    else{
        //copy the original number
        temp=num;
        //get the number of digits
        while(temp>0){
            temp=temp/10;
            no_of_digits++;
        }
        //after counting reset the temp to num
        temp=num;
        while(temp>0){
            //get the digit
            digit = temp%10;
            //digit exponent
            exp_result=1;
            for(int i=1;i<no_of_digits+1;i++){
                exp_result *=digit; 
            }
            sum = sum + exp_result;
            //slice the digit
            temp=temp/10;
        }
        if(num==sum){
            printf("entered number is an Armstrong number\n");
        }else{
            printf("entered number is not an armstrong number\n");
        }
    }
    return 0;
}