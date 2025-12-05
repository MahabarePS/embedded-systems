/*
hw2: WAP to accept a character in main function, if its lower case
     convert it into upper case. if its upper case convert it into
     lower case(in called function) & display the converted
     character in the main function.
*/
#include<stdio.h>
//declared conversion function
char charConv(char *);
int main(void){
    //get a char
    char ch=0, converted_char=0;
    printf("Enter a char: ");
    scanf(" %c",&ch);
    // pass the char as a reference to the function
    converted_char = charConv(&ch);
    printf("After casing: %c",converted_char);
    return 0;
}

char charConv(char *ch){
    if(*ch>=65 && *ch<=90){
        // make it lower case
        *ch+=32;
    }
    else if(*ch>=97 && *ch<=122){
        // make it upper case
        *ch-=32;
    }
    else{
        // if char is other than other than a-z
        return *ch;
    }
    // return the cased char
    return *ch;
}