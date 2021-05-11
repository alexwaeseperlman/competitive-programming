#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n; cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) cin >> arr[i];

	ll total = 0;
	for (ll i = 0; i < n - 1; i++) {
		ll small = min(arr[i], arr[i + 1]), large = max(arr[i], arr[i + 1]);
		while (large > small * 2) {
			total++;
			small *= 2;
		}
	}

	cout << total << endl;
}

int main() {
	ll t; cin >> t;
	while (t--) solve();
}
