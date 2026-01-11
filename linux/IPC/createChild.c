/*
 * author Prasad Mahabare
 * created on 11-01-2026-10h-18m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
PS: Create a child process using fork
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    pid_t c_pid = fork();
    if(c_pid<0){
        printf("Error while creating a process");
    }
    else if(c_pid==0){
        printf("Child Process ID: %d\n",getpid());
    }else{
        printf("Parent Procecss ID : %d\n",getppid());
    }
return 0;
}