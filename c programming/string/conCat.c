/*
PS: WAP to scan two strings & 
    concatenate 2nd string at the end of 1st string
*/
#include<stdio.h>
int main(void){
    int i=0,j=0;
    char str[10]={0}, abc[5]={0};
    printf("enter two strings: ");
    scanf("%s%s", str,abc);

    for(i=0;str[i]!=0;i++);

    for(j=0;abc[j]!=0;j++,i++){
        str[i]=abc[j];
    }
    printf("\n Concatenated string: %s",str);
    return 0;
}