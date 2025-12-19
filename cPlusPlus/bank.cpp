#include<iostream>
using namespace std;
#define DailyDeposit 20000

class BankAccount{
    private:
        static int total_acc, interest_rate,accId;
        static float total_money, withdraw, deposit;
    public:
        string name;
        float loan, ind_balance;
        BankAccount(string name, float ind_bal){
            accId++;
            this->name = name;
            total_acc++;
            if(ind_bal<1000.0){
                cout<<"Minimum bal should be greater than 10,000"<<endl;
            }else{
                ind_balance=ind_bal;
                //add the money to the total bank money
                total_money = total_money + ind_bal;
            }
        }
        //non-static member functions
        void deposit(float x){
            if(x>DailyDeposit){
                cout<<"Exceeded daildeposit limit!"<<endl;
            }
            else{
            deposit = x;
            total_money = total_money+deposit;
            }
        }
        void withdraw(float x){
            if(x>total_money){
                cout<<"Exceeded withdrawl limit!"<<endl;
            }
            else{
            deposit = x;
            total_money = total_money-withdraw;
            }
        }
        void calculate_interest(int t){
            int time = t;
            interest_rate = (ind_balance*interest_rate*time)/100;
        }
        //static member functions
        static void tot_acc_number(){
            cout<<"No of Account: "<<BankAccount::total_acc<<endl;
        }
        static void total_mon(){
            cout<<"Total Money in the bank: "<<BankAccount::total_money<<endl;
        }
        void display(){
            cout<<"AccountID: "<<accId<<endl;
            cout<<"name: "<<name<<endl;
            cout<<"Balance: "<<ind_balance<<endl;
        }

};
int BankAccount::total_acc=1000000;
int BankAccount::accId=100;
int BankAccount::interest_rate=5;
float BankAccount::total_money=0;

int main(){
    cout<<"-----------Bank Records-----------"<<endl;
    BankAccount a("Prasad",1000.0), b("BICARD",2000.0);
    a.deposit(100.0);
    a.display();

    //total accounts
    BankAccount::tot_acc_number();
    //overall bank balance
    BankAccount::total_mon();
    return 0;
}