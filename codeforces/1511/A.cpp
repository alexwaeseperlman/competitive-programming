#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n; cin >> n;

	ll upvotes = 0;
	for (ll i = 0; i < n; i++) {
		ll r; cin >> r;

		if (r == 1 || r == 3) upvotes++;
	}

	cout << upvotes << endl;
}

int main() {
	ll t; cin >> t;
	while (t--) solve();
}
