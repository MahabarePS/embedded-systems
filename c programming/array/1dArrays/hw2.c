/*
hw2: WAP to scan and display array in reverse order 
*/
#include<stdio.h>
#define ARRAY_SIZE 5
int main(void){
    int arr[ARRAY_SIZE],repeat;
    //get array elements
    printf("Enter integer for array of size %d : ",ARRAY_SIZE);
    for(repeat=0;repeat<ARRAY_SIZE;repeat++){
        scanf("%d",&arr[repeat]);
    }
    //print the array elements in reverse order
    printf("Array elements in reverse order: \n");
    for(repeat=ARRAY_SIZE-1;repeat>=0;repeat--){
        printf("%d\t",arr[repeat]);
    }
    return 0;
}