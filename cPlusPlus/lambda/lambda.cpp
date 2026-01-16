#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isEven(int x){
    return x%2==0;
}
int main(){
    vector<int> v = {1,2,3,4,5,6};

    int count1 = count_if(v.begin(),v.end(), isEven);

    cout<<"Even numbers (using regular function): "<<count1<<endl;

    int count2 = count_if(v.begin(),v.end(),[](int x){
                                            return x%2==0;
                                            });
    cout<<"Even numbers (using regular function): "<<count2<<endl;
    //
    int limit =3;
    // int count = count_if(v.begin(),v.end(),[limit](int x){return x>limit;});
    // cout<<"Numbers greater than "<<limit<<" = "<<count<<endl;
    // capture by referencec                                       
    int count = count_if(v.begin(),v.end(),[&limit](int x){return x>limit;});
    cout<<"Numbers greater than "<<limit<<" = "<<count<<endl;
    // capture all by value
    int a=10;
    int b=20;
    // lam is the function object
    auto lam = [=](){
        return a + b;
    };
    cout<<"Addition: "<<lam();
    return 0;
}