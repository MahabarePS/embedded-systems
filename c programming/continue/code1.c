#include<stdio.h>
int main()
{
    int i=0;
    for(i=1;i<11;i++)
    {
        if(i>=2 && i<=5)
            continue;
        printf("%d\t",i);
    }
}