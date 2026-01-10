/*
 * author Prasad Mahabare
 * created on 10-01-2026-23h-34m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
PS: implement a simple mutex
*/
#include<pthread.h>
#include<stdio.h>
pthread_t tid[2];
int counter;

void* trythis(){
    counter +=1;
    printf("Job %d started\n", counter);
    for(unsigned long i=0;i<0xFFFFFFF;i++);
    printf("Job %d finished\n",counter);
    return NULL;
}

int main(){
    for(int i=0;i<2;i++){
        pthread_create(&tid[i],NULL,trythis,NULL);
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}