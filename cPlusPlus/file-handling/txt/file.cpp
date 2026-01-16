#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream fout("sample.txt");
    fout<<"Name: Prasad\n";
    fout<<"Age: 28\n";
    fout<<"Skills: 70%\n";
    fout.close();
    cout<<"Data Written to file\n";

    ifstream fin("sample.txt");
    if(!fin){
        cout <<"Error: File does not exist\n";
        return 0;
    }
    string line;
    while(getline(fin,line)){
        cout<<line<<endl;
    }
    fin.close();
    return 0;
}