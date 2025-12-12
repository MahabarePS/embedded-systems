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
    // making the next pointer null
    newnode->next = NULL;
    // if empty node
    if(head==NULL){
        // create a new one
        head = newnode;
    }else{  // there are some nodes and lst node address will be in the head
        struct single *temp = head;
        // till its last node
        while(temp->next!=NULL){
            // move to the next node 
            temp = temp->next;
        }
        // then append a new node
        temp->next = newnode;
    }
 }

 void display_all_nodes(void){
    
 }