// COMSC-210 | Lab 38 | Joaquin Felix

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

// Function Prototypes

// gen_hash_index() calculates the hash index for the string
// arguments: a string
// returns: interger hash index
int gen_hash_index(const string& text);

// display_menu() shows the menu
// arguments: none
//returns: nothing
void display_menu();

// print_entries() prints first entries
// arguments: hash table
// returns: nothing
void print_entries(const map<int, list<string>>& hash_table);

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

    int choice = 0;

    while (choice != 6)
    {
        display_menu();

        cout << "Enter your choice: ";
        cin >> choice;

        cout << endl;

        switch (choice)
        {
            case 1: print_entries(hash_table);
                    break;
            case 6: cout << "Exiting program..." << endl;
                    break;
            default: cout << "Option not added yet." << endl;
        }

        cout << endl;
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


void display_menu() 
{
    cout << "===== HASH TABLE MENU =====" << endl;
    cout << "1. Display Hash Table" << endl;
    cout << "2. Search for a key" << endl;
    cout << "3. Add a key" << endl;
    cout << "4. Remove a key" << endl;
    cout << "5. Modify a key" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
}


void print_entries(const map<int, list<string>>& hash_table)
{
    int displayed = 0;

    for (const auto& pair : hash_table)
    {
        cout << "Hash Index: "
             << pair.first
             << endl;
        cout << "Codes: ";

        for (const string& code : pair.second)
        {
            cout << code << " ";
        }
        cout << endl << endl;

        displayed++;

        if (displayed >= DISPLAY_LIMIT)
        {
            break;
        }
    }
}










/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
