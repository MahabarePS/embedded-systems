#include<stdio.h>
int main(){
    int i=1;
    while(i<6)
    {
        printf("%d\t", i);
        if(i==3)
            break;
        i++;
    }
}