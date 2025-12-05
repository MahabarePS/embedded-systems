/*
hw6: Write a program to define a structure variable containing 
     one character, one integer & one float. Accept all the 
     contents using  -> operator, pass the structure variable 
     to function (call by reference) & display the contents in 
     called function using pointer
*/
#include<stdio.h>
//declare the struct 
struct bruh{
    char ch;
    int num;
    float fine;
}ik, *p=&ik;
//declare function that has struct as call by referencec
void damn(struct bruh*);
int main(void){
    //get a char
    printf("Enter a char: ");
    scanf(" %c",&p->ch);
    //get an integer
    printf("Enter an integer: ");
    scanf("%d",&p->num);
    //get a float number
    printf("Enter a float no: ");
    scanf("%f",&p->fine);
    //structure variable to function (call by reference)
    damn(&ik);
    return 0;
}
void damn(struct bruh *ptr){
    printf("Char: %c\nInteger: %d\nFloat: %f",ptr->ch,ptr->num,ptr->fine);
}