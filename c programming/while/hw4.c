//hw4: Accept m & n from user, print table of m up to n
#include<stdio.h>
int main(){
    int i=1,m=0,n=0,temp=0;
    printf("Enter the value of m: ");
    scanf("%d",&m);
    printf("\nEnter the value of n: ");
    scanf("%d",&n);
    while(i<=n){
        temp = m * i;
        printf("\n%d x %d : %d",m,i,temp);
        i++;
    }
}