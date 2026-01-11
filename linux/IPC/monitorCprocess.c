/*
 * author Prasad Mahabare
 * created on 11-01-2026-10h-18m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
/*
PS: Monitor the child process to make sure PID remains the same
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
        pid_t c_pid = fork();
        while(1){
        if(c_pid<0){
                printf("Error while creating a process");
                sleep(3);
        }
        else if(c_pid==0){
                printf("Child Process ID: %d\n",getpid());
                sleep(3);
        }else{
                printf("Parent Procecss ID : %d\n",getppid());
                sleep(3);
        }
}
return 0;
}