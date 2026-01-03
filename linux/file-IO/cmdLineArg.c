/*
 * author Prasad Mahabare
 * created on 03-01-2026-23h-43m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
int sum=0,arr[argc-1];
//convert char to int
for(int i=1;i<argc-1;i++){
arr[i] = atoi(argv[i]);
}
sum = arr[0];
//sum of array
for(int i=1;i<argc-1;i++){
sum = sum +arr[i];
}
printf("Sum of array: %d\n",sum);
return 0;
}