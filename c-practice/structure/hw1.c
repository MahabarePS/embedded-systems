/*
 * author Prasad Mahabare
 * created on 14-01-2026-17h-19m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
PS: Write a progrram to define a structure variable containing
    one character, one integer & one string. Accept & display all
    the contents using . operator
*/
#include<stdio.h>
struct student{
    int roll;
    char name[10];
    float marks;
};
int main(void){
    struct student s;
    printf("enter your name: ");
    scanf("%s",s.name);
    printf("enter your roll number: ");
    scanf("%d",&s.roll);
    printf("enter your marks: ");
    scanf("%f",&s.marks);

    printf("\nname: %s\nroll no.: %d\nmarks: %f",s.name,s.roll,s.marks);
    return 0;
}