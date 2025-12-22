/*
Problem Statement
Create a class named BankAccount to represent a bank account. Each account should store the
account holder’s name and current balance. The program must allow users to perform basic banking
operations such as depositing money, withdrawing money, and applying interest to the account
balance.
The system should also maintain information that is common to all bank accounts, such as the total
number of accounts created and a shared interest rate, using static data members and static
member functions.
Requirements
1. Use a class to model a bank account.
2. Use private data members to store:
o Account holder name
o Account balance
3. Implement a constructor to initialize account details and increment the total number of
accounts.
4. Provide member functions to:
o Deposit a valid amount into the account
o Withdraw an amount with proper validation
o Apply interest to the account balance
o Display account details in a formatted manner
5. Use static data members to:
o Store a common interest rate for all accounts
o Keep track of the total number of bank accounts created
o Keep track of the total money / balance in the bank
6. Use static member functions to:
o Display the total number of accounts
o Display the total balance in the bank

Demonstrate the working of the program by creating at least two bank account objects and
performing various operations on them.
*/
#include<iostream>
using namespace std;
class BankAccount{
    private:
        string name;
        double account_balance;
        static int total_no_acc;
        static double rate_of_interest, bank_balance;
    public:
        BankAccount(string name,double account_balance)
        :name(name),
         account_balance(account_balance)
        {
            //increment no_accounts
            total_no_acc++;
            //receive intial balance
            bank_balance += account_balance;
        }
        //static member function
        static void display_total_accounts(){
            cout<<"Total No. of Accounts: "<<total_no_acc<<endl;
        }
        static void display_bank_balance(){
            cout<<"Total Bank Balance: "<<bank_balance<<endl;
        }
        double deposit(double);
        double withdraw(double);
        double calculateInterest();
        void display_acc_details();
};
double BankAccount::deposit(double amount){
    // if amount is not valid
    if(amount<0.0){
        cout<<"Invalid deposit amount!"<<endl;
        return account_balance;
    }// deposit
    account_balance += amount;
    bank_balance +=amount;
    return account_balance;
}
double BankAccount::withdraw(double amount){
    //validation
    if(amount<=0 || amount > account_balance){
        cout<<"Invalid withdrawl amount!"<<endl;
        return account_balance;
    }
    //deduct amount from account
    account_balance -= amount;
    //deduct amount from bank
    bank_balance -=amount;
    return account_balance;
}
double BankAccount::calculateInterest(){
    double interest = (account_balance * rate_of_interest)/100.0;
    account_balance += interest;
    // bank-wide total must also grow
    bank_balance += interest;   // bank-wide total must also grow

    return account_balance;
}
void BankAccount::display_acc_details(){
    cout<<"--------Account Details--------"<<endl;
    cout<<"Name             : "<<name<<endl;
    cout<<"Account Balance  : "<<account_balance<<endl;
    cout<<"Rate of Interest : "<<rate_of_interest<<endl;
    cout<<"-------------------------------"<<endl;
}
int BankAccount::total_no_acc=0;
double BankAccount::bank_balance=0.0;
double BankAccount::rate_of_interest = 5.0;
int main(void){
    BankAccount acc1("Prasad", 250000.0);
    acc1.deposit(15000.0);
    acc1.withdraw(10000.0);
    acc1.calculateInterest();
    acc1.display_acc_details();

    BankAccount acc2("Jeff", 350000.0);
    acc2.deposit(25000.0);
    acc2.withdraw(20000.0);
    acc2.calculateInterest();
    acc2.display_acc_details();

    BankAccount::display_total_accounts();
    BankAccount::display_bank_balance();
    return 0;
}