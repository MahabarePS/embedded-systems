/*
hw1: Write a program to scan and display 3*4 
matrix in matrix form
*/
#include<stdio.h>
int main(){
    int arr[3][4]={0},i,j;
    printf("enter 12 number for 3x4 matrix: ");
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            scanf("%d\n",&arr[i][j]);
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}