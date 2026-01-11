/*
 * author Prasad Mahabare
 * created on 10-01-2026-23h-56m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
PS: convert an integer to string
*/
#include<stdio.h>
int main(void){
    //declaration
    int num=13, digit=0, size=0,i,j;
    unsigned char str[32],temp='\0';
    //get the user input
    printf("Enter an integer: ");
    scanf("%d",&num);
    if(num==0){
        str[0]='0';
        str[1]='\0';
        size = 1;
    }else{
        //extract the digit to char
        for(i=0;num>0;i++){
            size++;
            digit=num%10;
            str[i]=digit+'0';
            num = num/10;
        }
        str[size]='\0';
    }
    //reverse the string
    j=size-1;
    for(i=0;i<j;i++){
        temp = str[i];
        str[i]=str[j];
        str[j]=temp;
        j--;
    }
    //display string
    for(i=0;i<size;i++){
        printf("%c",str[i]);
    }
    return 0;
}