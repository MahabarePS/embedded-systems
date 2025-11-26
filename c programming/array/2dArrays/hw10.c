/*
hw10: Write a program to accept 4*4 matrix 
      & display the sum of each column along with the column number
*/
#include<stdio.h>
int main(){
    int matrix[4][4]={0},i,j,sum=0;
    printf("\n enter the elements for 4*4 matrix: ");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    for(i=0;i<4;i++){
        sum=0;
        for(j=0;j<4;j++){
            sum += matrix[j][i];
        }
        printf("\nsum of [%d]: %d",i,sum);
    }
}