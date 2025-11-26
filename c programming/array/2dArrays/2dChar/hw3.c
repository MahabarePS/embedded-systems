/*
hw3: Write a prrogram to scan 2d array character array & a character 
     find & display how many times that character appears in 2d aaray
*/
// Take row size - row
// Take col size - col
// Store array elements through scanf 
#include<stdio.h>
int main(){
    //declare variables for row, col, repeaters and a counter, finder
    int row=0,col=0,i,j,counter=0;
    //get the number of rows and columns
    printf("enter the size of rows: ");
    scanf("%d",&row);
    printf("enter the size of col: ");
    scanf("%d",&col);
    // declare array 
    char arr[row][col], find;
    //get the array elements
    printf("enter elements for char array of %d * %d: \n",row,col);
    for(i=0;i<row;i++){
        scanf("%s",arr[i]);
    }
    //Get a character to find
    printf("enter char to check its frequency: ");
    scanf(" %c",&find);
    //" %c": space before %c skips any buffer character after like "\n" or enter key
    //search char through the char array
    for(i=0;i<row;i++){
        for(j=0;arr[i][j]!='\0';j++)
            if(find==arr[i][j])
                counter++;
    }
    printf("Char'%c' appeared '%d' times ",find,counter);
}