#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a{0,1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < 1000000-1; i++) {
        next_permutation(a.begin(), a.end());
    }
    for (int i = 0; i < a.size(); i++) cout << a[i];
    cout << endl;
}