#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("sample.txt");

    // File stream is in fail state - File Does Not Exist
    if (!fin)
    {
        cout << "Error: File does not exist!\n";
        return 0;
    }

    string line;
    while (getline(fin, line))
    {
        cout << line << endl;
    }

    fin.close();
    return 0;
}
