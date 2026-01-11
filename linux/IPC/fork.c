/*
 * author Prasad Mahabare
 * created on 11-01-2026-23h-29m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*  fork.c  */
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
        pid_t c_pid = fork();
        //while(1){
        if(c_pid<0){
                printf("Error while creating a process");
        }
        else if(c_pid==0){
                printf("Child Process ID: %d\n",getpid());
                execl("./hpc","hpc",NULL);
        }else{
                printf("Parent Procecss ID : %d\n",getppid());
                }
        //}
}