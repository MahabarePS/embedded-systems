//hw12: print first 50 prime numbers
#include<stdio.h>
int main(){
    int total=1,curr=2,iterate,count;
    while(total<=50)
    {
        count=0;
        iterate=2;
        while(iterate<curr){    //checking divisior 
            if(curr%iterate == 0)
                count=1;
            iterate++;
        }
        if(count == 0){ // if no divisor 
            printf("%d\t", curr);
            total++;
        }
        curr++;     // next number check
    }
}