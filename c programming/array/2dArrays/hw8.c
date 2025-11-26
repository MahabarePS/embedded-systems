/*
hw8: Write a program to find the transpose of a 3x3 matrix
*/
#include<stdio.h>
int main(){
    int row=0,col=0,i,j;
    printf("\nenter the number of rows: ");
    scanf("%d",&row);
    printf("\nenter the number of col: ");
    scanf("%d",&col);
    if(row!=col){
        printf("\nrow must be equal to col to transpose ");
    }
    else{
        int matrix[row][col];
        printf("\nenter the elements for %dx%d matrix: ",row,col);
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                scanf("%d",&matrix[i][j]);
            }
        }
        printf("before transpose: \n");
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                printf("[%d][%d]: %d\t",i,j,matrix[i][j]);
            }
            printf("\n");
        }
        int transpose[row][col];
        printf("after transpose: \n");
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                transpose[i][j] = matrix[j][i];
                printf("[%d][%d]: %d\t",i,j,transpose[i][j]);
            }
            printf("\n");
        }
    }
}