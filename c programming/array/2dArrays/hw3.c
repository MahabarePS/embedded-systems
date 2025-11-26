/*
hw5: Accept two 3*3 matrices from user 
     store their addition in third matrix & display it
*/
#include<stdio.h>
int main(){
    int mat1[3][3]={0},mat2[3][3]={0},mat3[3][3]={0},i,j;
    printf("enter 9 values for matrix 1: ");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("enter 9 values for matrix 2: ");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&mat2[i][j]);
        }
    }
    printf("addition of matrix 1 and 2 in matrix 3: \n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            mat3[i][j] = mat2[i][j] + mat1[i][j];
            printf("mat3[%d][%d]: %d\t",i,j,mat3[i][j]);
        }
        printf("\n");
    }
}