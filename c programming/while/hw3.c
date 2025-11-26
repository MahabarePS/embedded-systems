//hw3: Print the multiplication table of a given number
#include<stdio.h>
int main(){
    int i=1,num, temp=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    printf("table of : %d",num);
    while(i<=10){
        temp = num * i;
        i++;
        printf("\n\t\t%d",temp);
    }
}