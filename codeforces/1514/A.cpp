#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n = 0; cin >> n;

	bool square = true;
	for (ll i = 0; i < n; i++) {
		ll k = 0; cin >> k;
		cout << sqrt(k) *sqrt(k) << " " << (sqrt(k) * sqrt(k) == k) <<  endl;
		square = square && ((sqrt(k) * sqrt(k)) == k);
	}

	cout << (square ? "NO" : "YES") << endl;
}

int main() {
	ll t; cin >> t;

	while (t--) solve();
}
