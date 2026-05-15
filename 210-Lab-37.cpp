// COMSC-210 | Lab 37 | Joaquin Felix

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Constants
const string DATA_FILE = "lab-37-data-3.txt";

int sum_ascii(const string& text);

int main() {
    ifstream fin(DATA_FILE);
    
    if (!fin)
    {
        cout << "ERROR: Could not open "
             << DATA_FILE
             << endl;
        
        return 0;
    }


    string code;
    long long grand_total = 0;

    while (fin >> code)
    {
        grand_total += sum_ascii(code);
    }

    fin.close();

    cout << "Grand total: "
         << grand_total
         << endl;
    

    return 0;
}


// sum_ascii() calculates the sum of the ASCII values of the string
// arguments: a string
// returns: interger ASCII total


int sum_ascii(const string& text)
{
    int total = 0;

    for (char ch : text)
    {
        total += (int) ch;
    }

    return total;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
