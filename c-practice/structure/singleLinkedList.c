/*
 * author Prasad Mahabare
 * created on 14-01-2026-17h-37m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
PS: trying to program singly linked list
*/
#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[20];
    int roll;
    float marks;
    //self referencing wild pointer
    struct student *next;
}*head=NULL;

void add_node(void);

void add_node(void){
    //if next==NULL -> mallock it 
}