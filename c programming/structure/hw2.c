/*
hw2: WAP to define a structure variable containing one character,
     one integer & one string. Accept & display all the contents 
     using -> operator.
*/
#include<stdio.h>
//declare structure
struct arrow{
    char ch;
    int num;
    char str[30];
};
int main(void){
    struct arrow a1, *p = &a1;
    // get a character
    printf("Enter a character: ");
    scanf(" %c",&p->ch);
    // get an integer
    printf("Enter an integer: ");
    scanf("%d",&p->num);
    // get a string
    printf("Enter a string: ");
    scanf("%s",p->str);

    printf("\nChar: %c\nInteger: %d\nString: %s",p->ch,p->num,p->str);
}