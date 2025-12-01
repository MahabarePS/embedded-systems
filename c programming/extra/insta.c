/*
PS: Create an array of 100 integers in C. Set the 5th element to
    10 and the 90th element to 50. The rest must be 0.
*/
#include<stdio.h>
int main(void){
    int arr[100]={[4]=10,[99]=50};
    printf("%d",arr);
    return 0;
}