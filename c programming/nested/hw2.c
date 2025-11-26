/*
    *
   **
  ***
 ****
*****

*/
#include<stdio.h>
int main(){
    int space=0,row=1,col=1;        
    while(row<4){
        while(col<(4-1)){
            printf("*");
        }
        col--;
        row++;
    }
}