#include<iostream>
using namespace std;
class Base{
    protected:
        int i =5;
};

class D1: virtual public Base{
    protected:
        int j = 6;
};
class D2: virtual public Base{
    protected:
        int k = 7;
};
class D3: public D1, public D2{
    public:
    int calSum(){
        return i+j+k;
    }
};
int main(){
    D3 d;
    cout<<"i+j+k = "<<d.calSum()<<endl;
    return 0;
}