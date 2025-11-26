/*
hw7: Write a program to display 
     sum of diagonal elements of 4x4 matrix
*/
#include <stdio.h>
int main(){
    int row=0,col=0,i,j,add_diag=0;
    printf("\nEnter the size of row: ");
    scanf("%d",&row);
    printf("\nEnter the size of col: ");
    scanf("%d",&col);
    int matrix[row][col];
    printf("\nEnter elements for %dx%d matrix: \n",row,col);
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(i==j)
                add_diag = add_diag + matrix[i][j];
        }
    }
    printf("\nAddition of diagonal elements: %d",add_diag);
}