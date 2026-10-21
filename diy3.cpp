
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string s, word, result = "";

    cout << "Enter a sentence: ";
    getline(cin, s);

    stringstream ss(s);

    while (ss >> word)
    {
        if (result == "")
        {
            result = word;
        }
        else
        {
            result = word + " " + result;
        }
    }

    cout << "Reversed sentence: " << result << endl;

    return 0;
}
