
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {3, 8, 1, 9, 4};

    auto it = find_if(v.begin(), v.end(),
                      [](int x) {
                          return x > 5;
                      });

    if (it != v.end())
        cout << "First number greater than 5: " << *it << endl;

    sort(v.begin(), v.end());

    auto lb = lower_bound(v.begin(), v.end(), 4);

    cout << "Lower bound index: "
         << (lb - v.begin()) << endl;

    vector<int> p = {1, 2, 3};

    cout << "Permutations:\n";

    do {
        for (int x : p)
            cout << x << " ";

        cout << endl;

    } while (next_permutation(p.begin(), p.end()));

    return 0;
}

