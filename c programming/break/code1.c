#include<stdio.h>
int main(){
    int i=0;
    for(i=1;i<6;i++){
        printf("%d\t",i);
        if(i==3)
            break;
    }
}