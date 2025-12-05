#include<stdio.h>
struct abc
{
    char a;
    int b;
}t;
//unpacked
#pragma pack(1)
//packed
struct xyz
{
    char a;
    int b;
}m;

int main(void){
    printf("t=%u\n",sizeof(t));
    printf("m=%u\n",sizeof(m));
    return 0;
}