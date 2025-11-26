/*
*
**
***
****
*****
*/
#include<stdio.h>
int main(){
    int out=1;
    while(out<5)
    {
        int in=1;
        while(in<=out){
            printf("*");
            in++;
        }
        printf("\n");
        out++;
    }
}