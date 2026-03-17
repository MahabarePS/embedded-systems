/*
 * author Saquib Shaikh
 * created on 14-03-2026-21h-15m
 * github: https://github.com/saquibshaikh14
 * copyright 2026
*/
/*
Embedded Event Queue:
    Imagine a microcontroller receiving events:
    - sensor trigger
    - UART message
    - timer event
    - button press

    event1 -> event2 -> event3

    New events are added at the tail and processed from the head

    Structure:  head -> event1 -> event2 -> event3
                                    ^
                                    tail                             
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
//event ID's are usually "enumerations", not raw numbers.
typedef enum{
    EVENT_BUTTON_PRESS,
    EVENT_UART_RX,
    EVENT_TIMER,
    EVENT_SENSOR_TRIGGER
}EventType;
//What should a node contain
typedef struct EventNode{
    EventType event_id;      
    struct EventNode *next;
}EventNode;
//List container
typedef struct EventList{
    EventNode *head;
    EventNode *tail;
    uint32_t count;
}EventList;

int main(void){
    EventNode* create_event_node(EVENT_UART_RX);
    return 0;
}

EventNode* create_event_node(uint32_t event_id){
    //allocate memory for new node
    EventNode *newEventNode = malloc(sizeof(EventNode));
    if(newEventNode==NULL){
        return NULL;
    }
    //initialize fields
    newEventNode->event_id=event_id;
    newEventNode->next=NULL;
    //return pointer
    return newEventNode;
}
// Creating enqueue function
void enqueue(EventList *queue, EventNode *node){
    //if list is empty
    if(queue->head==NULL){
        queue->head = node;
        queue->tail = node;
    }else{
        queue->tail->next = node;
        queue->tail = node;
    }
    //Increase count
    queue->count++;
}