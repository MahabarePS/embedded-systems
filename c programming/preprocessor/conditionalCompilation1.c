/*
 * author Prasad Mahabare
 * created on 28-12-2025-15h-34m
 * github: https://github.com/MahabarePS
 * copyright 2025
*/
/*
PS: Example demostrating preprocessor directive 
    - conditional compilation 2
*/
#include<stdio.h>
#define PI 3.14
#define CIR_AREA(RADIUS) PI*RADIUS*RADIUS //nesting macros
#define SQR_AREA(S)S*S
#define RECT_AREA(L,B) L*B
#define TRI_AREA(B,H) (B*H)/2
#define AREA 2
int main(void){
    float square_side=0, rect_length=0,rect_breadth=0;
    float circle_radius=0,tri_base=0,tri_height=0,area=0;
    #if AREA == 1
        printf("\nEnter radius of circle: ");
        scanf("%f",&circle_radius);
        area = CIR_AREA(circle_radius);
        printf("\narea of circle: %.2f\n",area);
    #elif AREA == 2
        printf("\nenter side of square: ");
        scanf("%f",&square_side);
        area = SQR_AREA(square_side);
        printf("\narea of sqaure: %.2f\n",area);
    #elif AREA == 3
        printf("\nenter length & breadth of rectangle: ");
        scanf("%f%f",&rect_length,&rect_breadth);
        area = RECT_AREA(rect_length, rect_breadth);
        printf("\narea of rectangle: %.2f\n",area);
    #else
        printf("\nenter base & height of triangle: ");
        scanf("%f%f",&tri_base,&tri_height);
        area = TRI_AREA(tri_base,tri_height);
        printf("\narea of triangle: %.2f\n",area);
    #endif
    return 0;
}