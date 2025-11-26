//Check whether the given number is palindrome or not
#include<stdio.h>
int main()
{
    int num=0, digit, reverse=0, original;
    printf("Enter a number: ");
    scanf("%d",&num);
    original = num;
    while(num!=0){
        digit = num % 10;   //extract the last digit
        reverse = reverse * 10 + digit;   // reverse the order
        num = num/10;  
    }
    if(reverse==original)
        printf("palindrome");
    else
        printf("not palindrome");
}