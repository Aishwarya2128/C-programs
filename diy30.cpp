
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int marks;
};

int main() {
    ofstream out("students.txt");

    out << "Asha 85\n";
    out << "Ravi 95\n";
    out << "Meera 90\n";

    out.close();

    ifstream in("students.txt");

    if (!in) {
        cout << "File opening failed\n";
        return 1;
    }

    Student s[10];
    int count = 0;

    while (count < 10 && in >> s[count].name >> s[count].marks) {
        count++;
    }

    if (count == 0) {
        cout << "No student records found\n";
        return 0;
    }

    int topper = 0;

    for (int i = 1; i < count; i++) {
        if (s[i].marks > s[topper].marks)
            topper = i;
    }

    cout << "Topper Details\n";
    cout << "Name: " << s[topper].name << endl;
    cout << "Marks: " << s[topper].marks << endl;

    in.close();

    return 0;
}
