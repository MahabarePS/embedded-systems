/*
hw1: WAP to accept a number in main function, increment it by 10
     in called function and display the result in main function.
*/
#include<stdio.h>
//Declare function
int incre(int *);
int main(void){
    //Initialize the variables to  0
    int num = 0, r = 0;
    //Take an integer from user
    printf("Enter an integer: ");
    scanf("%d",&num);
    //pass the integer to the function and store the return value in ret
    r = incre(&num);
    //print the incremented value
    printf("Integer ++ by 10: %d",r);
    return 0;
}
//function defination
int incre(int *ptr){
    *ptr = *ptr + 10;
    return *ptr;
}