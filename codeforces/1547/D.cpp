#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	ll n; cin >> n;

	vector<ll> x(n);
	for (ll i = 0; i < n; i++) cin >> x[i];

	ll c = x[0];
	cout << 0 << " ";
	for (ll i = 1; i < n; i++) {
		cout << (c & ~x[i]) << " ";
		c = x[i] ^ (c & ~x[i]);
	}
	cout << endl;
}

int main() {
	ll t; cin >> t;
	while (t--) solve();

}
