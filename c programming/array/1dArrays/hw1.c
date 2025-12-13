/*
hw1: WAP to scan and display array
*/
#include<stdio.h>
int main(void){
    //declare an empty array
    int arr[5]={0},i;
    //get the array elements from user
    printf("Enter array elements of size 5: ");
    for(i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    //display the array elements
    for(i=0;i<5;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}