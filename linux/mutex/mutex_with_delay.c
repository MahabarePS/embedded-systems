/*
 * author Prasad Mahabare
 * created on 04-01-2026-11h-06m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
PS: Synchronizing threads using mutex
*/
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_mutex_t lock;
long counter =0;
void* worker(){
for(int i=0;i<2000;i++){
        pthread_mutex_lock(&lock);//enter critical section
        printf("Thread 1: increment counter by 1");
        counter++;
        pthread_mutex_unlock(&lock);//exit critical section
        sleep(1);
        }
return NULL;
}

void* display(){
for(int i=0;i<2000;i++){
        pthread_mutex_lock(&lock);
        printf("Thread 2: current counter: %ld\n",counter);
        pthread_mutex_unlock(&lock);
        sleep(1);
}
return NULL;
}
int main(){
        pthread_t t1,t2;
        pthread_mutex_init(&lock,NULL);

        pthread_create(&t1,NULL,worker,NULL);
        pthread_create(&t2,NULL,display,NULL);

        pthread_join(t1,NULL);
        pthread_join(t2,NULL);

        pthread_mutex_destroy(&lock);

        printf("Final counter: %ld\n",counter);
return 0;
}