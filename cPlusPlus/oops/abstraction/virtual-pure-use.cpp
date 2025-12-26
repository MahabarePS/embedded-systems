#include<iostream>
using namespace std;
class Shape{
    public:
        //Pure vitual function
        virtual void draw()=0;
        virtual double area()=0;
        virtual double perimeter()=0;
        //non-pure concrete function
        void info(){
            cout<<"This is shape"<<endl;
        }
        //desctructor
        virtual ~Shape() {}
};
class Circle: public Shape{
    double radius;
    public:
        Circle(double r){
            radius = r;
        }
        //overrriding draw()
        void draw(){
            cout<<"-----------------------"<<endl;
            cout<<"Drawing a Circle"<<endl;
        }
        // overriding area()
        double area(){
            return 3.14 * radius * radius;
        }
        // overriding perimeter()
        double perimeter(){
            return 2 * 3.14 * radius;
        }
        ~Circle() {}
};
class Square: public Shape{
    double side;
    public:
        Square(double s){
            side = s;
        }
        // overrriding draw()
        void draw(){
            cout<<"-----------------------"<<endl;
            cout<<"Drawing a Square"<<endl;
        }
        // overriding area()
        double area(){
            return side * side;
        }
        // overriding perimeter()
        double perimeter(){
            return 4*side;
        }
        ~Square() {}
};
class Rectangle: public Shape{
    double length, width;
    public:
        Rectangle(double l, double w){
            length =l;
            width = w;
        }
        // overrriding draw()
        void draw(){
            cout<<"-----------------------"<<endl;
            cout<<"Drawing a Rectangle"<<endl;
        }
        // overriding area()
        double area(){
            return length * width;
        }
        //overriding perimeter()
        double perimeter(){
            return 2*(length+width);
        }
        ~Rectangle() {}
};
int main(){
    //avoiding the wild 
    Shape *s=nullptr;
    int ch;
    
    Circle c(4);
    Square sq(5);
    Rectangle r(6,7);

    s = &c;
    s->draw();
    cout<<"Area of Circle: "<<s->area()<<endl;
    cout<<"Perimeter of Circle: "<<s->perimeter()<<endl;

    s = &sq;
    s->draw();
    cout<<"Area of Square: "<<s->area()<<endl;
    cout<<"Perimeter of Square: "<<s->perimeter()<<endl;

    s = &r;
    s->draw();
    cout<<"Area of Rectangle: "<<s->area()<<endl;
    cout<<"Perimeter of rectangle: "<<s->perimeter()<<endl;

    return 0;
}