//hw1: Write a program to display addition of 1 to 10
#include<stdio.h>
int main(){
    int i=0, add=0;
    while(i<11){
        add = add + i;
        i++;
    }
    printf("additon of 1-10: %d",add);
}