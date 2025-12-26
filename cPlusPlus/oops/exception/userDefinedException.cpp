#include<iostream>
using namespace std;
//User defined exception class
class InsufficientFundsException{
    public:
        double amount;
        InsufficientFundsException(double amt): amount(amt){}
};

int main(){
    double balance = 5000;
    double withdraw = 70000;
    try{
        if(withdraw>balance){
            throw InsufficientFundsException(withdraw-balance);
        }
        cout<<"Transaction Successful\n";
    }
    catch(InsufficientFundsException &e){
        cout<<"funds short by: "<<e.amount<<endl;
    }
    return 0;
}