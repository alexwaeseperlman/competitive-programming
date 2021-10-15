#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

void solve() {
    int n; cin >> n;
    map<ull, ull> a;
    ull sum = 0;
    for (int i = 0; i < n; i++) {
        ull x; cin >> x;
        a[x]++;
        
        sum += x;
    }
    if (((2*sum) % n) != 0) {
        cout << 0 << endl;
        return;
    }
    ull target = (2*sum)/n;
    ull combinations = 0;
    for (auto [value, count] : a) {
        if (value > target / 2) {
            break;
        }
        if (target-value==value) {
            combinations += count * (count - 1) / 2;
            break;
        }
        combinations += count * a[target-value];
    }
    cout << combinations << endl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}
