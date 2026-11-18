
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

struct Student {
    string name;
    int marks;
};

int main() {
    vector<Student> s = {
        {"Asha", 88},
        {"Ravi", 95},
        {"Meera", 72},
        {"Rahul", 80}
    };

    sort(s.begin(), s.end(),
         [](const Student &a, const Student &b) {
             return a.marks > b.marks;
         });

    cout << "Students in descending order:\n";

    for (auto x : s) {
        cout << x.name << " " << x.marks << endl;
    }

    int pass = count_if(s.begin(), s.end(),
                        [](const Student &x) {
                            return x.marks >= 75;
                        });

    cout << "Number of students passed: " << pass << endl;

    int total = accumulate(s.begin(), s.end(), 0,
                           [](int sum, const Student &x) {
                               return sum + x.marks;
                           });

    cout << "Total Marks: " << total << endl;

    return 0;
}
