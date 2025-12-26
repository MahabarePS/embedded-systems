#include<iostream>
using namespace std;
template <typename T>
T add(T a, T b){
    return a+b;
}

template <typename T>
void Swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    cout<<"--------Templates for Add---------"<<endl;
    cout<<"Add Integers : "<<add(10,20)<<endl;
    cout<<"Add Floats   : "<<add(2.5f,3.5f)<<endl;
    cout<<"Add Strings  : "<<add(string("Hello"), string("World!"))<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"Add Chars    : "<<add('a','b')<<endl;

    cout<<"--------Templates for Swap---------"<<endl;
    int i1=10, i2=20;
    Swap(i1,i2);
    cout<<"Swapped Integers : "<<i1<<" "<<i2<<endl;
    float i1=10.0f, i2=20.0f;
    Swap(i1,i2);
    cout<<"Swapped floats : "<<i1<<" "<<i2<<endl;
    char i1='a', i2='b';
    Swap(i1,i2);
    cout<<"Swapped chars : "<<i1<<" "<<i2<<endl;

    return 0;
}