#include<iostream>
using namespace std;
#define SQR(x) x*x

inline int max(int x, int y){
    return (x>y)?x:y;
}

inline int square(int x){
    return (x*x);
}
int main(){
    cout<<" max (20,10): "<< max(20,10)<<endl;
    cout<<" sqr (20,10): "<< SQR(20+10)<<endl;
    return 0;
}