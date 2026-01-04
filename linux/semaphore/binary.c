/*
 * author Prasad Mahabare
 * created on 04-01-2026-23h-23m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t sem;
int counter=0;

void* increment(){
for(int i=0;i<10;i++){
        sem_wait(&sem);
        counter++;
        printf("Thread %ld incremented counter to %d \n",pthread_self(),counter);
        sem_post(&sem);
        usleep(100);
        }
return NULL;
}

int main(){
pthread_t th1,th2;
sem_init(&sem,0,1);
pthread_create(&th1,NULL,increment,NULL);
pthread_create(&th2,NULL,increment,NULL);

pthread_join(th1,NULL);
pthread_join(th2,NULL);

sem_destroy(&sem);
printf("Final counter = %d\n",counter);

return 0;
}