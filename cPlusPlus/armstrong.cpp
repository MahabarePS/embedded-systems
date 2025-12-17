/*
PS: calculate the armstrong number
*/
#include<iostream>
using namespace std;
bool armstrong(int);
int main(){
    cout<<"-------armstrong number check-------"<<endl;
    //get a number from the user
    int num;
    cout<<"Enter an integer: ";
    cin>> num;
    if(num!=0){
        //send it to a function as a parameter
        cout<< boolalpha << armstrong(num) << endl;
    }else{
        cout<<"Invalid number!"<<endl;
    }
    return 0;
}
bool armstrong(int x){
    int temp=0,sum=0,no_of_digits=0, full_int;
    //count number of digits
    temp = x;
    while(temp>0){
        no_of_digits++;
        temp = temp/10;
    }
    full_int = x;
    //single out the digit
    while(full_int>0){
        int curr =  full_int%10;
        int d = 1;
        //get the exponent of the curr
        for(int i=1;i<=no_of_digits;i++){
            d = d * curr;
        }
        //accumulate the exponents
        sum = sum + d;
        full_int = full_int/10;
    }
    return sum == x;
}