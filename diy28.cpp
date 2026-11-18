
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("nums.txt");

    if (!file) {
        cout << "File not found\n";
        return 1;
    }

    int n, count = 0, sum = 0;
    int minimum, maximum;

    if (!(file >> n)) {
        cout << "File is empty\n";
        return 0;
    }

    minimum = maximum = n;

    do {
        sum += n;
        count++;

        if (n < minimum)
            minimum = n;

        if (n > maximum)
            maximum = n;

    } while (file >> n);

    cout << "Count: " << count << endl;
    cout << "Sum: " << sum << endl;
    cout << "Minimum: " << minimum << endl;
    cout << "Maximum: " << maximum << endl;

    file.close();

    return 0;
}
