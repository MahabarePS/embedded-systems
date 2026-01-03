/*
 * author Prasad Mahabare
 * created on 03-01-2026-23h-43m
 * github: https://github.com/MahabarePS
 * copyright 2026
*/
#include<stdio.h>
int main(int argc, char* argv[]){
FILE *fptr;
char c;
fptr=fopen("bicard_031026.txt","w");
if(fptr==NULL){
printf("Error creating file ...\n");
return 1;
}
printf("File created successfully \n");
//Takes character by character
fprintf(fptr,"Hello from Bicard to Linux batch!\n");
//Takes block by clock
fputs("Thanks, Welcome again \n",fptr);
fptr=fopen("bicard_031026.txt","r");
printf("Reading file contents char by char: \n");
while((c=fgetc(fptr))!=EOF){
printf("%c",c);
}
fclose(fptr);
printf("File closed \n");
return 0;
}