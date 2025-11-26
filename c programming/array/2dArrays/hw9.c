/*
hw9: Write a program to accept 4*4 matrix and display the 
     sum of each row along with the row number
*/
#include<stdio.h>
int main(){
    int row=0,col=0,i,j,sum=0,temp=0;
    // Get the values of row and column for the matrix
    printf("\nenter the number of row: ");
    scanf("%d",&row);
    printf("\nenter the number of col: ");
    scanf("%d",&col);
    printf("\nenter the number for %dx%d matrix: \n",row,col);
    // Get the values in the matrix 
    int matrix[row][col];
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    // Display the sum for each row
    for(i=0;i<row;i++){
        sum=0;
        for(j=0;j<col;j++){
            //save the addition of the rows in temp
            sum = sum + matrix[i][j];
            
        }printf("\nsum of row [%d]: %d\t",i,sum);
    }
}