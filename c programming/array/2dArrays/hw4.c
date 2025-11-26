/*
hw4: Write a program to find max of matrix
*/
#include<stdio.h>
int main(){
    int matrix[4][4]={0},i,j,max;
    printf("enter 9 numbers for 4x4 matrix: ");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    max = matrix[0][0];
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(matrix[i][j]>max){
                max = matrix[i][j];
            }
        }
    }printf("maxt of matrix is: %d",max);
}