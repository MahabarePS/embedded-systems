/*
hw3: WAP to define a structure variable containing one character,
     one integer & one integer array. Accpet & display all the contents
     using . operator
*/
#include<stdio.h>
// declare strcuture
struct arrDemo{
    char ch;
    int num;
    int arr[7];
};
int main(void){
    //declare struct variable
    struct arrDemo ar={0};
    //get a char
    printf("Enter a char: ");
    scanf(" %c",&ar.ch);
    //get an integer
    printf("Enter an integer: ");
    scanf("%d",&ar.num);
    //get an integer array
    printf("Enter 7 integers for array: \n");
    for(int i=0;i<7;i++){
        scanf("%d",&ar.arr[i]);
    }
    //display char and integer
    printf("\nChar: %c\nInteger: %d",ar.ch,ar.num);
    //display integer array
    printf("\nInt array: ");
    for(int i=0;i<7;i++)
    {
        printf("%d\t",ar.arr[i]);
    }
    return 0;
}