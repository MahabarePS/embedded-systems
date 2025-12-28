/*
 * author Prasad Mahabare
 * created on 28-12-2025-15h-06m
 * github: https://github.com/MahabarePS
 * copyright 2025
*/
/*
PS: Example demostrating preprocessor directive macro
*/
#include<stdio.h>
#define MAX 5 
#define PI 3.14
int main(void){
    int arr[MAX],i; float rad,area;
    printf("\nenter %d numbers :",MAX);
    //Store the integers
    for(i=0;i<MAX;i<i++)
    {
        scanf("%d",&arr[i]);
    }
    //Display the integers
    for(i=0;i<MAX;i++){
        printf("%d\t",arr[i]);
    }
    //Circle area calculation
    printf("\nenter radius of a circle: ");
    scanf("%f",&rad);
    //Calculating area of a circle
    area = PI * rad * rad;
    printf("\narea of a circle: %.2f\n",area);
    return 0;
}