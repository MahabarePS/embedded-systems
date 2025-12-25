#include<iostream>
using namespace std;
class BankAccount{
    private:
        string name;
        double balance;
    public:
        BankAccount(string n, double bal): name(n), balance(bal){}

        string getName() const noexcept {return name;}
        //getter for balance
        double getBalance() const noexcept {return balance;}

        //deposite money
        void deposite(double amount){
            if(amount<0){
                throw invalid_argument("Deposite amount cannot be negative");
            }
            balance +=amount;
        }

        //withdraw money
        void withdraw(double amount){
            if(amount<0){
                throw invalid_argument("Withdraw amount cannot be negative");
            }

            if(amount>balance){
                throw runtime_error("Insufficient funds in account"+name);
            }
            balance -=amount;
        }

        //will not throw exception
        void printBalance() const noexcept{
            cout<<name<<" Balance: "<<balance<<endl;
        }

        //transfer money 
        void transferTo(BankAccount &to, double amount){
            double oldFrom = balance;
            double oldTo = to.balance;
            try{
                withdraw(amount);//may throw
                to.deposite(amount);//should not thrw, but safe with rollback
            }
            catch(...){
                //RollBack to maintain strong guarantee
                balance = oldFrom;
                to.balance = oldTo;
                throw;
            }
        }
};
int main(){
    BankAccount alice("Alice",5000);
    BankAccount bob("Bob",3000);

    cout<<"-----Initial balances-----";
    alice.printBalance();
    bob.printBalance();

    //withdraw > balance
    try{
        cout<<"\nAttempting to withdraw 6000 from Alice\n";
        alice.withdraw(6000);
    }
    catch(const exception e){
        cout<<"Exception caught: "<<e.what()<<endl;
    }
    cout<<"\n----Balances after failed withdraw---"<<endl;
    alice.printBalance();
    bob.printBalance();

    //proper withdraw
    try{
        cout<<"\nAttempting to withdraw 2000 from Alice\n";
        alice.withdraw(2000);
    }
    catch(const exception e){
        cout<<"Exception caught: "<<e.what()<<endl;
    }
    cout<<"\n----Balances after Successful withdraw---"<<endl;
    alice.printBalance();
    bob.printBalance();

    //attempt a transfer that will fail
    try{
        cout<<"\nAttempting to tranfer 6000 from Alice to Bob\n";
        alice.transferTo(bob,6000);
    }
    catch(const exception e){
        cout<<"Exception caught: "<<e.what()<<endl;
    }
    cout<<"\n----Balances after Successful transfer---"<<endl;
    alice.printBalance();
    bob.printBalance();

    //attempt a transfer that will succeed
    try{
        cout<<"\nAttempting to tranfer 2000 from Alice to Bob\n";
        alice.transferTo(bob,2000);
    }
    catch(const exception e){
        cout<<"Exception caught: "<<e.what()<<endl;
    }
    cout<<"\n----Balances after Successful transfer---"<<endl;
    cout<<"\n----------final balance----------"<<endl;
    alice.printBalance();
    bob.printBalance();

    return 0;
}