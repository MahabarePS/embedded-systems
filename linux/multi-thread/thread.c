/*
 * author Prasad Mahabare
 * created on 03-01-2026-23h-46m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
//gcc thread.c -o thread -lpthread
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
//Task for thread 1
void* print_msg1(){
printf("Thread 1 task started .......\n");
for(int i=0;i<20;i++){
printf("From Thread: 1 --> value of i is: %d\n",i);
sleep(1);
}
printf("Thread 1 task completed ......\n");
return NULL;
}
//Task for thread 2
void* print_msg2(){
printf("Thread 2 task started .....\n");
for(int x=0;x<10;x++)
{
printf("From Thread: 2 --> value of j is: %d\n",x);
sleep(1);
}
printf("Thread 2 task completed .....\n");
return NULL;
}
int main(){
// declare thread objects
pthread_t t1, t2;
// create two threads
pthread_create(&t1,NULL,print_msg1,NULL);
pthread_create(&t2,NULL,print_msg2,NULL);
//wait till threads to finish
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("All threads are finished\n");
return 0;
}