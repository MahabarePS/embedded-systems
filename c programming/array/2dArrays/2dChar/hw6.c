/*
hw6: Write a program to concatenate all strings of
     2d array (arr[3][20]) in a single 1d array & display it
*/
#include<stdio.h>
int main(){
     int i,j,k=0,_2drow,_2dcol,_1drow,_1dcol;
     printf("Enter the size of 2d row: ");
     scanf("%d",&_2drow);
     printf("Enter the size of 2d col: ");
     scanf("%d",&_2dcol);
     _1dcol=(_2drow*_2dcol);
     char _2d[_2drow][_2dcol], _1d[_1drow][_1dcol];
     printf("Enter the elements of 2d [%d][%d]: \n",_2drow,_2dcol);
     for(j=0;j<_2drow;j++){
          scanf("%s",&_2d[j]);
     }
     for(i=0;i<_2drow;i++){
          for(j=0;_2d[i][j]!='\0';j++){
               _1d[0][k]=_2d[i][j];
               printf("1d[0][%d]: %c\n",k,_1d[0][k]);
               k++;   
          }
     }
     _1d[0][k]='\0';
     printf("1d[0][%d]: %c\n",k,_1d[0][k]);
}