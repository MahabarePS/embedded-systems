/*
hw5: write a program to count even and odd elements
*/
#include<stdio.h>
int main(){
    int matrix[3][4]={0},i,j,even=0,odd=0;
    printf("enter 12 elements for 3x4 matrix: \n");
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            if(matrix[i][j]%2==0)
                even++;
            else
                odd++;
        }
    }
    printf("\neven element count: %d",even);
    printf("\nodd element count: %d",odd);
}