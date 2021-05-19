#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll aprimes[9] = {2, 11, 101, 1009, 10007, 100003, 1000003, 10000019, 100000007};
ll cprimes[9] = {3, 13, 103, 1013, 10009, 100019, 1000033, 10000079, 100000037};

void solve() {
	ll a, b, c;
	cin >> a >> b >> c;

	ll gcd = cprimes[c-1];
	ll x = aprimes[a-c] * gcd, y = cprimes[b-c] * gcd;

	cout << x << " " << y << endl;
}


int main() {
	ll t;
	cin >> t;
	while (t--) solve();
}
