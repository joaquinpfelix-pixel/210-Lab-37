#include <iostream>
#include <string>

using namespace std;

int sum_ascii(const string& text);

int main() {
    string user_input;

    cout << "Enter a string: ";
    cin >> user_input;

    cout << "ASCII sum: "
         << sum_ascii(user_input)
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
