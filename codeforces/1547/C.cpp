#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	ll k, n, m; cin >> k >> n >> m;

	vector<ll> mono(n), poly(m);
	for (ll i = 0; i < n; i++) cin >> mono[i];
	for (ll i = 0; i < m; i++) cin >> poly[i];

	vector<ll> out;
	ll i = 0, j = 0;
	while (i < n || j < m) {
		bool changed = false;
		for (; i < n && mono[i] <= k; i++) {
			changed = true;
			out.push_back(mono[i]);
			if (mono[i] == 0) k++;
		}
		
		for (; j < m && poly[j] <= k; j++) {
			changed = true;
			out.push_back(poly[j]);
			if (poly[j] == 0) k++;
		}
		if (!changed) break;
	}
	if (i == n && j == m) {
		for (ll i = 0; i < out.size(); i++) cout << out[i] << " ";
		cout << endl;
	}
	else cout << -1 << endl;
}

int main() {
	ll t; cin >> t;
	while (t--) solve();
}
