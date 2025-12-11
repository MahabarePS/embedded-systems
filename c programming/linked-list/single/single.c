/*
PS: Create a single linked list
*/
 #include<stdio.h>
 #include"single.h"     //custom header
 //declare a node structure
 struct single{
    int id;
    char name[10];
    //self referential structure
    struct single *next;
 }*head=NULL;           //empty list
 
 int main(void){
    //create a menu for the user entry
    int ch=0;
    do{
        printf("---Single Linked List---\n1. Add a node\n2. Display all nodes\n>_");
        scanf("%d",&ch);
        if(ch){
            switch(ch){
                case 1: append_node();
                        break;
                case 2: display_all_node();
                        break;
            }
        }else{
            printf("choice outside the menu!");
        }
    }while(ch!=3);
    return 0;
 }

 void append_node(void){
    // the node should be the size of the structure
    struct single *newnode = malloc(sizeof(struct single));
    printf("\nEnter id: ");
    scanf("%d",&newnode->id);
    printf("\nEnter name: ");
    scanf("%s",newnode->name);
    //making the next pointer null
    newnode->next = NULL;

    if(head==NULL){
        head = newnode;
    }else{
        struct single *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
 }