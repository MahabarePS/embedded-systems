/*
hw3: Write a program to scan and display
     integer array
*/
#include<stdio.h>
int main(){
    int arr[5] = {0}, *ptr = arr, i;
    printf("enter 5 array elements: ");
    for(i=0;i<5;i++,ptr++)
    {
        scanf("%d",ptr);
    }
    ptr=arr;
    for(i=0;i<5;i++,ptr++){
        printf("[ %d ] \t", *ptr);
    }
    return 0;
}