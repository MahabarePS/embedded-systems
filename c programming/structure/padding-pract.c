#include<stdio.h>
struct B{
    char a;
    double b;
    int c;
    short d;
}t;
int main(void){
    printf("t=%u",sizeof(t));
    return 0;
}