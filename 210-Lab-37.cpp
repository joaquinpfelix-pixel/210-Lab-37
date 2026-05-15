// COMSC-210 | Lab 37 | Joaquin Felix

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>

using namespace std;

// Constants
const string DATA_FILE = "lab-37-data-3.txt";
const int HASH_SIZE = 1000;
const int DISPLAY_LIMIT = 10;

// gen_hash_index() calculates the hash index for the string
// arguments: a string
// returns: interger hash index
int gen_hash_index(const string& text);

int main() {
    ifstream fin(DATA_FILE);
    
    if (!fin)
    {
        cout << "ERROR: Could not open "
             << DATA_FILE
             << endl;
        
        return 1;
    }

    // Hash table;
    // key  = has index
    // value = list of codes
    map<int, list<string>> hash_table;

    string code;


    // Read file data
    while (fin >> code)
    {
        int hash_index = gen_hash_index(code);

        // Insert code into list at that hash index
        hash_table[hash_index].push_back(code);
    }

    fin.close();

    int displayed = 0;

    for (auto pair : hash_table)
    {
        cout << "Hash Index: "
             << pair.first
             << endl;
        cout << "Codes: ";

        for (string code_value : pair.second)
        {
            cout << code_value << " ";
        }
        cout << endl << endl;

        displayed++;

        if (displayed >= DISPLAY_LIMIT)
        {
            break;
        }
    }
    

    return 0;
}


// gen_hash_index() calculates the hash index for the string
// arguments: a string
// returns: interger hash index
int gen_hash_index(const string& text)
{
    int total = 0;

    for (char ch : text)
    {
        total += (int) ch;
    }

    return total % HASH_SIZE;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
