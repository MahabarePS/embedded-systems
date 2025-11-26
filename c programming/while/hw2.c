//hw2: print first 10 odd numbers
#include <stdio.h>
int main(){
    int i=1,count=0;
    while(count<=10){
        if(i%2!=0){
            printf("\n%d",i);
            count++;
        }
        i++;
    }
}