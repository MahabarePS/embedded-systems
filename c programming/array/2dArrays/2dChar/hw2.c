/*
hw2: Write a program to calculate & display the 
     length of each string in 2d character array arr[3][20]
*/
#include<stdio.h>
int main(){
    char arr[3][20]={0};
    int i=0,j=0, count;
    printf("enter 3 strings: \n");
    for(i=0;i<3;i++)
        scanf("%s",arr[i]);

    for(i=0;i<3;i++){
        count=0;
        for(j=0;arr[i][j]!='\0';j++)
            count++;
        printf("\n[%d]: %d",i,count);
    }   
}