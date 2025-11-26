/*
hw2: Write a program to display sum of elements of 3*4 matrix
*/
#include<stdio.h>
int main(){
    int arr[3][4]={0},i,j,next=0,curr=0,add=0;
    printf("enter the 12 numbers for 3x4 matrix: ");
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            scanf("%d",&arr[i][j]);
        }
        
    }
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            curr = arr[i][j];
            add += curr;
            
        }
    }
    printf("addition:%d ",add);
}