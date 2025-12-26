#include<iostream>
#include<stdexcept>
#include<vector>
#include<limits>
#include<cmath>
using namespace std;
int main(){
    int a, b;
    cout<<"Enter two Integers: ";
    cin>>a>>b;

    try{
        if(b==0){
            throw runtime_error("Division by zero");
        }
        else if(a<0||b<0){
            throw invalid_argument("Negative input not allowed");
        }
        else{
            cout<<"Division: "<<a/b<<endl;
        }
    }
    catch (const runtime_error &e){
        cout<<"Runtime Error: "<<e.what()<<endl;
    }
    catch (const invalid_argument &e){
        cout<<"Invalid Argument: "<<e.what()<<endl;
    }
    // out of range
    try{
        vector<int> v = {10,20,30};
        cout<<"Accessing vector elements at index 5 ...\n";
        cout<<v.at(5)<<endl; // throws out_of_range
    }
    catch(const out_of_range &e){
        cout<<"Out of Range Error: "<<e.what()<<endl;
    }
    // Domain error
    try{
        double x = 4.0;
        if(x<0){
            throw domain_error("Square root of negative number");
        }
        cout<<sqrt(x)<<endl;

        double y = 4.0;
        if(y<=0){
            throw domain_error("Logarithm defined only for positive numbers");
        }
        cout<<log(y)<<endl;
    }
    catch(const domain_error &e){
        cout<<"Domain error: "<<e.what()<<endl;
    }
    //Invalid logic
    try{
        int balance = 5000;
        int withdraw = 70000;

        if(withdraw>balance){
            throw logic_error("Withdrawl amount exceeds amount balance");
        }

    }catch(const logic_error &e){
        cout<<"Logic Error: "<<e.what()<<endl;
    }
    //Standard exception caught by generic catch(const exception &e)
    try{
        string s = "Hello";
        if(s.length()>3){
            throw length_error("String length exceeds allowed limit");
        }
    }
    catch(const exception &e){
        cout<<"Standard exception: "<<e.what()<<endl;
    }
    //non-standard exception caught by catch()
    try{
        cout<<"I am getting a million dollars!!";
        throw 100;
    }
    catch(...){
        cout<<"Unknown exception occured!"<<endl;
    }
    return 0;
}
