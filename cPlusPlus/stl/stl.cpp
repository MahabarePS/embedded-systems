#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> numbers ={5,2,8,1};
    //numbers.begin() is an iterator
    sort(numbers.begin(), numbers.end());
    cout<<"Sorted numbers: "<<endl;
    for(int n: numbers){
        cout<<n<<" ";
    }
    cout<<endl;
    return 0;
}