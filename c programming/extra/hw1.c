/*
hw1: WAP to find number of words in the string entered by user
*/
#include<stdio.h>
int main(void){
    char str[50] = {0};
    int i = 0, word = 0, ch = 0;
    printf("enter words: ");
    scanf("%[^\n]s",str);
    while(str[i]!='\0'){
        if(str[i]==5){
            str[i]='X';
        }
        else{
            i++;
        }
    }
    printf("modified char at index 5: %s",str);
    return 0;
}