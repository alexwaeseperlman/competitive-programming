#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll base = 1000000007;

const ll k = 100000000;
const ll r = k;

vector<ll> factorials(k+1), invfactorials(k+1);

ll pow(ll n, ll p, ll base) {
    vector<ll> squares(log2(p)+1, n);
    for (ll i = 1; i < squares.size(); i++) {
        squares[i] = (squares[i-1]*squares[i-1])%base;
    }

    ll out = 1;
    for (ll i = 0, m = 1; m <= p; i++, m <<= 1) {
        if (p & m) out = (out * squares[i])%base;
    }
    return out;
}

int main() {
    factorials[0] = 1;
    invfactorials[0] = 1;
    for (ll i = 1; i <= k; i++) {
        factorials[i] = (factorials[i-1] * i) % base;
        invfactorials[i] = (invfactorials[i-1] * pow(i, base-2, base)) % base;
    }

    ll p2 = pow(2, 2*r, base), num = 1;
    if (k % 2) num = pow(2, r);

    ll total = 0;
    for (ll twos = k/2; twos >= 0; twos--) {
        const ll ones = k-twos*2;
        total += (((((
            ((num * invfactorials[ones]) % base) * 
            ((invfactorials[twos]*invfactorials[twos])%base))%base)
            * factorials[k]) % base)
            ) % base;


        total %= base;
        num = (num*p2)%base;
    }

    cout << total%base << endl;
}
