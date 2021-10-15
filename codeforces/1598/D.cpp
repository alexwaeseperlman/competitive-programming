#include <bits/stdc++.h>
using namespace std;
using ull = long long;

ull choose(ull n, ull k) {
    if (k > n) return 0;
    ull out = 1, j = 1;
    for (ull i = n-k+1; i <= n; i++) {
        out *= i;
        if (j <= k) out /= j;
        j++;
    }
    return out;
}

void solve() {
    ull n; cin >> n;
    vector<pair<ull, ull>> ab;
    vector<ull> ca(n), cb(n);

    for (ull i = 0; i < n; i++) {
        ull a, b; cin >> a >> b;
        a--, b--;
        ab.emplace_back(a, b);
        ca[a]++;
        cb[b]++;
    }

    ull total = choose(n, 3);
    for (ull i = 0; i < n; i++) {
        total -= (ca[ab[i].first]-1)*(cb[ab[i].second]-1);
    }
    cout << total << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
