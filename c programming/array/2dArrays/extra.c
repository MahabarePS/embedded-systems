/*
hw1: Write a program to scan and display 
     array in reverse order
*/
#include<stdio.h>
// int main(){
//     int arr[3][4]={0},i,j;
//     printf("enter 12 numbers for 3x4 matrix: ");
//     for(i=0;i<3;i++){
//         for(j=0;j<4;j++){
//             scanf("%d",&arr[i][j]);
//         }
//     }
//     //currently i=3,j=4
//     printf("\nMatrix in reverse order:\n");
//     for(i=2;i>=0;i--){
//         for(j=3;j>=0;j--){
//             printf("%d\t",arr[i][j]);
//         }
//         printf("\n");
//     }
// }
int main(){
    int arr[3][4]={0},i=0,j=0;
    printf("enter 12 numbers for 3x4 matrix: ");
    while(i<3){
        j=0;
        while(j<4){
            scanf("%d",&arr[i][j]);
            j++;
        }
        i++;
    }
    i=2,j=3;
    while(i>=0)
    {
        j=3;
        while(j>=0){
            printf("%d\t",arr[i][j]);
            j--;
        }
        printf("\n");
        i--;
    }
}