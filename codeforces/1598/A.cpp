#include <bits/stdc++.h>
using namespace std;

void solve() {
    int c; cin >> c;
    vector<bool> row1(c), row2(c);
    for (int j = 0; j < c; j++) {
        char x; cin >> x;
        row1[j] = x == '1';
    }
    for (int j = 0; j < c; j++) {
        char x; cin >> x;
        row2[j] = x == '1';
    } 

    bool passable = true;

    for (int i = 0; i < c; i++) {
        passable = passable && (!row1[i] || !row2[i]);
    }

    if (passable && !row1[0] && !row2[c-1]) cout << "YES" << endl;
    else cout << "NO" << endl;


}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
