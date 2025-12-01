/*
hw2: Copy a string
*/
#include<stdio.h>
int main(void){
    char src[50]={'\0'},dst[50]={'\0'};
    printf("Enter dst string: ");
    scanf("%s",dst);
    printf("Enter src string: ");
    scanf("%s",src);
    int index=0;
    while(dst[index]!='\0'){
        index++;
    }
    int i=0;
    while(src[i]!='\0'){
        dst[index]=src[i];
        index++; i++; 
    }
    dst[index]='\0';
    printf("------After copying src to dst------\n");
    printf("dst strings is: %s",dst);
    return 0;
}