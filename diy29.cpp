
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input("in.txt");
    ofstream output("out.txt");

    if (!input || !output) {
        cout << "File opening failed\n";
        return 1;
    }

    string line;
    int count = 1;

    while (getline(input, line)) {
        output << count << ". " << line << endl;
        count++;
    }

    cout << "File copied successfully\n";

    input.close();
    output.close();

    return 0;
}
