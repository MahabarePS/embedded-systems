#include<iostream>
#include<fstream>
using namespace std;
int main(){
    fstream file;
    file.open("data.txt",ios::out);

    file<<"Name: Prasad\n";
    file<<"Age: 28\n";
    file<<"Skills: 80%\n";

    file.close();

    file.open("data.txt",ios::in);
    string line;
    while(getline(file,line)){
        cout<<line<<endl;
    }
    file.close();
    return 0;
}