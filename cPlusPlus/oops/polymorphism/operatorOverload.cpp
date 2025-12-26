#include<iostream>
using namespace std;
class Complex{
    private:
        int real, img;
    public:
        Complex(){
            real = 0;
            img = 0;
        }
        Complex(int r, int i){
            real = r;
            img = i;
        }
        //Without operator overloading
        // Complex Add(Complex obj){
        //     Complex r;
        //     r.real = this->real + obj.real;
        //     r.img = this->img + obj.img;
        //     return r;
        // }
        //With operator overloading
        //old way Complex Operator+(Complex obj){} This can change the object value
        Complex operator+(const Complex &obj) const{ // safer and best
            Complex res;
            // c1 real    c2 real
            res.real = real + obj.real;
            res.img =  img + obj.img;
            return res;
        }
        //==
        bool operator==(const Complex &obj) const{
            return (real == obj.real && img == obj.img);
        }
        //>
        bool operator>(const Complex &obj) const{
            int mag1 = real + img;
            int mag2 = obj.real + obj.img;
            return mag1>mag2; 
        }
        //pre-increment
        Complex &operator++(){
            real++;
            img++;
            return *this; // just return the same obj after modification
        }
        //pre-decrement
        Complex &operator--(){
            real--;
            img--;
            return *this;
        }
        //post-increment
        Complex operator++(int){
            Complex old = *this; // step 1
            real++;
            img++;               // step 2
            return old;          // step 3
        }
        //post-decrement
        Complex operator--(int){
            Complex old = *this;
            real--;
            img--;
            return old;
        }
        void printComplex(){
            cout<<real<<" +i"<<img<<endl;
        }
};
int main(void){
    Complex c1(10, 2), c2(3,4);
    Complex c3, c4;

    cout<<"c1 : ";
    c1.printComplex();

    cout<<"c2 : ";
    c2.printComplex();

    c3 = c1 + c2;
    cout<<"c1+c2 is: ";// calls c1.operator+(c2)
    c3.printComplex();

    c4 = c1 + c2 + c3;
    cout<<"c1+c2+c3 is: ";// calls c1.operator+(c2)
    c4.printComplex();

    //==
    if(c1==c2){
        cout<<"Equal"<<endl;
    }
    else{
        cout<<"not Equal"<<endl;
    }

    //>
    if(c1>c2){
        cout<<"Greater"<<endl;
    }else{
        cout<<"Not Greater"<<endl;
    }

    //pre-increment ++object
    c1++;
    cout<<"c1 is: ";
    c1.printComplex();

    //post-increment object++
    Complex temp = c2++;
    cout<<"Original value of c2: ";
    temp.printComplex();
    cout<<"After obj++: of c2: ";
    c2.printComplex();

    //pre-decrement --obj
    c1--;
    cout<<"c1 is: ";
    c1.printComplex();

    //post-decrement obj--;
    Complex temp2 = c2--;
    cout<<"Original value of c2: ";
    temp2.printComplex();
    cout<<"After obj++: of c2: ";
    c2.printComplex();

    return 0;
}