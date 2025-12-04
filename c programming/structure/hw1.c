/*
hw1: WAP to define a structure variable containing one character,
     one integer & one string. Accept & display all the contents
     using . operator
*/
#include<stdio.h>
//declaring a structure 
struct demo{
    char ch;
    int num;
    char str[50];
};
int main(void){
    //declare structure variable 
    struct demo d1;
    printf("Enter a character: ");
    //accept char using .
    scanf(" %c",&d1.ch);
    printf("Enter an integer: ");
    //accept int using .
    scanf("%d",&d1.num);
    printf("Enter a string: ");
    //accept string using .
    scanf("%[^\n]s",d1.str);

    //print the struct members using . operator
    printf("char: %c \ninteger: %d \nstring: %s", d1.ch,d1.num,d1.str);

}