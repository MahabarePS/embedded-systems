#include<stdio.h>
struct Test{
    char a;
    int b;
    double c;
    short d;
    char e;
}t;
int main(void){
    printf("t=%u",sizeof(t));
    return 0;
}