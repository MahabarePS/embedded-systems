/*
hw3: WAP to accept array of 10 integer elements in main function, do the addition of elements 
     of array in called function & display the result in main function( using index method).
*/
#include<stdio.h>
//declare function
int add(int *);
int main(void){
    // get integer array of 10 and a variable to store function result
    int arr[10]={0}, sum=0;
    printf("Enter the array elements: ");
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }
    // passed the base address of array to a function using call by reference
    sum = add(arr);     // add(&arr[0]); also works
    //displayed the result
    printf("Addition of array elements: %d",sum);
    return 0;
}
// function defination
int add (int *ptr){
    //to store the addition of elements
    int sum = 0;
    for(int i=0;i<10;i++){
        //index method.
        sum += ptr[i];
    }
    // return the result
    return sum;
}