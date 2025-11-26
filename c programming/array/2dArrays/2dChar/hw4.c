/*
hw4: Write a program to find and display 
     number of vowels & consonants in 2d array arr[4][10]
*/
#include<stdio.h>
int main(){
    int i, j, vowels=0, consonants=0;
    char arr[4][10];
    printf("enter the values for 4*10: \n");
    for(i=0;i<4;i++){
        scanf("%s",arr[i]);
    }
    //Check for vowels
    for(i=0;i<4;i++){
        for(j=0;arr[i][j]!='\0'&&j<10;j++){
            if(arr[i][j]=='a' || arr[i][j]=='A'||
                arr[i][j]=='e' || arr[i][j]=='E'||
                arr[i][j]=='i' || arr[i][j]=='I'||
                arr[i][j]=='o' || arr[i][j]=='O'||
                arr[i][j]=='u' || arr[i][j]=='U')
                vowels++;
            else
                consonants++;
        }
    }printf("Total Vowels: %d\t Total Consonants: %d",vowels,consonants);
}