/*
hw4 Pointer: Write a program to display numbers at 
     odd indexes only in an integer array
*/
#include<stdio.h>
int main(void){
     int arr[10]={0},i;
     int *ptr=arr;
     printf("Enter int array elements:\n");
     for(i=0;i<10;i++,ptr++)
     { 
          scanf("%d",ptr);
     }
     ptr=arr;
     printf("Odd index elements are: \n");
     for(i=0;i<10;i++,ptr++){
          if(i%2!=0){
               printf("\tarray[%d]: %d\n",i,*ptr);
          }
     }
     return 0;
}