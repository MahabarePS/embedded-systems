/*
PS: Understanding union behavior
*/
#include<stdio.h>
struct abc{
    char c;
    int x;
};
//union declare
union xyz{
    int y;
    struct abc w;
}t;
int main(void){
    printf("\nsize: %u",sizeof(t));
    return 0;
}