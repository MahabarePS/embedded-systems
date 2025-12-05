/*
hw5: WAP to define a structure variable containing one character,
     one integer & one integer array. Accept all the contents using
     . operator, pass the structure variable to function (call by 
     value) & display the contents in function called using . 
     operator.
*/
#include<stdio.h>
//declare struct
struct fun{
    char ch;
    int num;
    int arr[10];
};
// pass struct variable as a function parameter
void display(struct fun f);

int main(void){
    struct fun f;
    //get a char
    printf("Enter a char: ");
    scanf(" %c",&f.ch);
    //get an integer
    printf("Enter an integer: ");
    scanf("%d",&f.num);
    // get integer elements for array
    printf("Enter integers for array: ");
    for(int i=0;i<10;i++){
        scanf("%d",&f.arr[i]);
    }
    // pass the struct variable to function
    display(f);
    return 0;
}

void display(struct fun s){
    // displaying structure members through function call by value
    printf("Char: %c\nInteger: %d\n",s.ch,s.num);
    printf("Inetger array: ");
    for(int i=0;i<10;i++){
        printf("%d\t",s.arr[i]);
    }
}