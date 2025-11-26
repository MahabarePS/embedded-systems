#include<stdio.h>
int main(){
    int i=0,j=0,r=0,ch=0;
    do{
        printf("\nenter two numbers ");
        scanf("%d%d",&i,&j);
        printf("1. add\n2. sub\n3. mul\n4. Exit \nenter choice: ");
        scanf("%d",&ch);
        if(ch==1){
            r = i+j;
            printf("\naddition : %d",r);
        }
        else if(ch==2){
            r = i - j;
            printf("\nsubtraction: %d",r);
        }
        else if(ch==3){
            r = i * j;
            printf("\nmultiplication: %d",r);
        }
        else if(ch==4){
            printf("\nexit");
        }
        else{
            printf("\nInvalid Choice");
        }
        }while(ch!=4);
        return 0;
}