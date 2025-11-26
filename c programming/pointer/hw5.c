/*
hw5: Write a program to find max of integer array
*/
#include<stdio.h>
int main(void){
    int arr[5]={0},i,*ptr=arr,max=0;
    printf("Enter array elements: \n");
    for(i=0;i<5;i++,ptr++){
        scanf("%d",ptr);
    }
    ptr=arr;
    max=*ptr;
    for(i=1;i<5;i++,ptr++){
        if(*ptr>max){
            max=*ptr;
        }
    }
    printf("Max of an integer array is: %d",max);
}