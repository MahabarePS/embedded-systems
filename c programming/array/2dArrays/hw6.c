/*
hw6: Write a program to check 
     whether 3*3 matrix is diagonal or not
*/
#include<stdio.h>
int main(){
     int matrix[3][3]={0},i,j,diagonal, diagonal_count=0,zero_count=0;
     printf("enter 9 elements for 3x3 matrix: ");
     for(i=0;i<3;i++){
          for(j=0;j<3;j++){
               scanf("%d",&matrix[i][j]);
          }
     }
     diagonal = matrix[0][0]; //initialized to the first element
     for(i=0;i<3;i++){
          for(j=0;j<3;j++){
               if(diagonal==matrix[i][j])
                    diagonal_count++;
               else if(matrix[i][j]==0)
                         zero_count++;
          }
     }
     if((diagonal_count==3)&&(zero_count==6))
          printf("\n Diagonal matrix");
     else
          printf("\n not Diagonal matrix");
}