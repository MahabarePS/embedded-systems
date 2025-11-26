#include<stdio.h>
int main(){
    int i=0;
    while(i<10){
        i++;
        if(i>=2 && i<=5)
             continue;
        printf("%d\t",i);
    }
}