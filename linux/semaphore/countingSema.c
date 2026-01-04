/*
 * author Prasad Mahabare
 * created on 04-01-2026-23h-33m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define NUM_THREADS 5
#define NUM_PRINTERS 2

sem_t sem;

void* printer(void* arg){
        int id=*(int*)arg;
        printf("Thread %d: waiting for a printer...\n",id);
        sem_wait(&sem);//take a printer (decrement)
        printf("Thread %d: got a printer, printing ....\n",id);
        sleep(2);//simulate printing queue
        printf("Thread %d: finished printing, releasing printer\n",id);
        sem_post(&sem);//release printer (increment)
        return NULL;
}

int main(){
        pthread_t threads[NUM_THREADS];
        int thread_ids[NUM_THREADS];

        //Initialise counting semaphore with value = NUM_PRINTERS
        sem_init(&sem,0,NUM_PRINTERS);

        for(int i=0;i<NUM_PRINTERS;i++){
                thread_ids[i] = i + 1;
                pthread_create(&threads[i],NULL,printer,&thread_ids[i]);
        }
        for(int i=0;i<NUM_THREADS;i++){
                pthread_join(threads[i],NULL);
        }
        sem_destroy(&sem);
return 0;
}