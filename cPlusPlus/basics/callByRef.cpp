#include<iostream>
using namespace std;
void swapByRef(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
int main(){
    int a = 10, b =20;
    cout<< "Before swap: ";
    cout<<" a: "<<a<<" b: "<<b<<endl;
    swapByRef(a,b);
    cout<<"After swap : ";
    cout<<" a: "<<a<<" b: "<<b<<endl;
    return 0;
}