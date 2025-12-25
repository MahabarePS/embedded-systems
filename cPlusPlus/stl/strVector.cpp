#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout<<"1. Vector elements: ";
    for (int x: v){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"Size     : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;
    if(!v.empty()){
        cout<<"Vector is not empty "<<endl;
    }
    cout<<"Element at index 1: "<<v[1]<<endl;
    cout<<"Element at index 10: "<<v[10]<<endl;
    cout<<"Front element: "<<v.front()<<endl;
    cout<<"Last element: "<<v.back()<<endl;
    //insert(): at a specific position
    v.insert(v.begin()+1, 15); //inster 15 at 1
    //
    //v.erase(v.begin(),2); //removes element at index 2
    cout<<" "<<endl;
    v.resize(10,100);
    cout<<"4. Vector elements: ";
    for (int x: v){
        cout<<x<<" ";
    }
    v.clear();
    cout<<"Capacity after clear(): "<<v.capacity()<<endl;
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);
    sort(v.begin(),v.end());
    cout<<"5. Vector elements: ";
    for (int x: v){
        cout<<x<<" ";
    }
    //used very often
    auto pos = find(v.begin(), v.end(),35);
    if(pos!=v.end()){
        int index = distance(v.begin(),pos);
        cout<<"Element found in vector ar position "<<index<<endl;
    }else{
        cout<<"Elements not found! "<<endl;
    }
    int c = count(v.begin(), v.end(),35);
    cout<<"53 appears "<<c<<" times\n";
    v.shrink_to_fit();
    cout<<"Final size: "<<v.size()<<endl;
    cout<<"Final capacity: "<<v.capacity()<<endl;
    return 0;
}