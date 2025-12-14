/*
hw3: WAP to display numbers at odd indexes only
*/
#include<stdio.h>
#define ARRAY_SIZE 6
int main(void){
    int arr[ARRAY_SIZE],index;
    //get array elements
    printf("Enter elements for array of size %d: ",ARRAY_SIZE);
    for(index=0;index<ARRAY_SIZE;index++){
        scanf("%d",&arr[index]);
    }
    //display odd index elements
    for(index=1;index<ARRAY_SIZE;index +=2){
        printf("Array[%d]: %d\t",index,arr[index]);
    }
    return 0;
}