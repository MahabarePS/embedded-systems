#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>> n;
    //dynamically allocate the array
    int *arr = new int[n];
    //get the array elements
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //find the min
    int min=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<=min){
            min = arr[i];
        }
    }
    cout<<"Min of array is: "<<min<<endl;
    //find the max
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    cout<<"Max of array is: "<<max<<endl;
    //find the sum
    int sum=0;
    for(int i=0;i<n;i++){
        sum = sum + arr[i];
    }
    cout<<"sum of array is: "<<sum<<endl;
    delete[] arr;
    arr = nullptr;
}