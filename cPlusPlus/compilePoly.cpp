#include<iostream>
#define pi 3.14
using namespace std;
class Sample{
    public:
        void area(int);
        void area(int, int);
        void area(float, float);
        void area(float);
};
void Sample::area(int a){
    cout<<"Area of a circle: "<< pi * a*a;
}
void Sample::area(int a, int b){
    cout<<"Area of a rectangle: "<< a*b;
}
void Sample::area(float h, float b){
    cout<<"Area of a trangle: "<<(h*b)/2;
}
void Sample::area(float a){
    cout<<"Area of a square: "<<a * a;
}
int main(){
    int a,b,r,ch;
    float h,w,x;
    Sample obj;
    cout<<"-----Calculate the area------"<<endl;
    cout<<"1. Area of circle "<<endl;
    cout<<"2. Area of a rectangle "<<endl;
    cout<<"3. Area of a triangle "<<endl;
    cout<<"4. Area of a square "<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch){
        case 1: 
                cout<<"Enter radius of a circle: ";
                cin>>r;
                obj.area(r);
                break;
        case 2: 
                cout<<"Enter sides of a rectangle: ";
                cin>>a>>b;
                obj.area(a,b);
                break;
        case 3: 
                cout<<"Enter height and width of a triangle: ";
                cin>>h>>w;
                obj.area(h,w);
                break;
        case 4: 
                cout<<"Enter a side of a square: ";
                cin>>x;
                obj.area(x);
                break;
        default:
                cout<<"Invalid choice!!1"<<endl;
    }
    return 0;
}