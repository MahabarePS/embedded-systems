/*
hw4: WAP to define a structure variable containing one character,
     one integer & one integer array. Accept & display all the 
     contents using-> operator.
*/
#include<stdio.h>
//declare structure
struct arrDemo{
    char ch;
    int num;
    int arr[10];
};
int main(void){
    //declare the struct variable 
    struct arrDemo ar = {0}, *p = &ar;
    //get a char
    printf("Enter a char: ");
    scanf(" %c",&p->ch);
    //get an integer
    printf("Enter an integer: ");
    scanf("%d",&p->num);
    //only get the elements user enter
    printf("Enter integer elemnets < 10: \n");
    int count = 0;
    while(count<10){
        // check how many integers user entered
        if(scanf("%d",&p->arr[count])){
            count++;
        }
        int ch = getchar();
        // if the user press "enter"
        if(ch=='\n'){
            break;
        }
    }
    //display the struct members using -> operator
    printf("Char: %c\nInteger: %d\n",p->ch,p->num);
    printf("Entered array elements: \n");
    for(int i=0;i<count;i++){
        printf("%d\t",p->arr[i]);
    }
    return 0;
}