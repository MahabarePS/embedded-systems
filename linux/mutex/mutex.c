/*
 * author Prasad Mahabare
 * created on 04-01-2026-10h-52m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
PS: Synchronizing threads using mutex
*/
#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock;
long counter =0;

void* worker(){
for(int i=0;i<100000;i++){
        pthread_mutex_lock(&lock);//enter critical section
        counter++;
        pthread_mutex_unlock(&lock);//exit critical section
        }
return NULL;
}
int main(){
        pthread_t t1,t2;
        pthread_mutex_init(&lock,NULL);

        pthread_create(&t1,NULL, worker,NULL);
        pthread_create(&t2,NULL,worker,NULL);

        pthread_join(t1,NULL);
        pthread_join(t2,NULL);

        pthread_mutex_destroy(&lock);

        printf("Final counter: %ld\n",counter);
return 0;
}