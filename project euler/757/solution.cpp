#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 1e14;

ll stealthyNumber(ll x, ll k) {
    return x*x*k*k - k*x*x - x*k*k + x*k;
}

vector<ll> stealthyNumbers;

int main() {
    ll iters = 0;
    ll total = 0;
    for (ll x = 2; true; x++) {
        ll k = x-1;
        if (stealthyNumber(x, k) > N) break;
        for (; true; k++) {
            iters++;
            ll n = stealthyNumber(x, k);
            if (n > N) break;
            stealthyNumbers.push_back(n);
        }
    }
    sort(stealthyNumbers.begin(), stealthyNumbers.end());
    cout << unique(stealthyNumbers.begin(), stealthyNumbers.end()) - stealthyNumbers.begin() << " " << iters << endl;
}
