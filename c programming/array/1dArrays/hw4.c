/*
 * author Prasad Mahabare
 * created on 02-01-2026-11h-49m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
PS: Convert an integer to binary
*/
#include<stdio.h>
int main(void){
    //get a number from the user
    int num=0, quo=0, i=0, arr[8]={0};
    printf("Enter an integer: ");
    scanf("%d",&num);
    //edge case of 0
    if(num==0){
        printf("0");
        return 0;
    }
    // convert to binary
    while(num>0){
        arr[i]=num%2;
        num = num/2;
        i++;
    }
    //print in reverse
    for(int j = i-1; j>=0;j--){
        printf("%d",arr[j]);
    }
    return 0;
}