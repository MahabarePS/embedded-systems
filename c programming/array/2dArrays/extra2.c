/*
hw3: Write a program to display
     numbers at odd indexes only
*/
#include<stdio.h>
int main(){
    int arr[3][4]={0},i,j;
    printf("enter 12 elements for 3x4 matrix: ");
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("elements at odd indices: \n");
    for(i=0;i<3;i++){
            for(j=0;j<4;j++){
                if((i%2!=0)&&(j%2!=0))
                    printf("arr[%d][%d]: %d\t",i,j,arr[i][j]);
            }
        printf("\n");
    }
}