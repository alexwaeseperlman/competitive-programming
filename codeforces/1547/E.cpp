#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	ll n, k; cin >> n >> k;

	vector<ll> temps(n, numeric_limits<ll>::max() / 2);
	vector<ll> acs(n, numeric_limits<ll>::max() / 2);


	vector<ll> positions(k);
	for (ll i = 0; i < k; i++) cin >> positions[i];
	for (ll i = 0; i < k; i++) {
		cin >> acs[positions[i]-1];
	}
	
	for (ll d : {-1, 1}) {
		ll ac = numeric_limits<ll>::max() / 2;
		for (ll i = d == -1 ? n-1 : 0; i < n && i >= 0; i += d) {
			ac++;
			ac = min(ac, acs[i]);

			temps[i] = min(ac, temps[i]);
		}
	}

	for (ll i = 0; i < n; i++) cout << temps[i] << " ";
	cout << endl;
}

int main() {
	ll t; cin >> t;

	while (t--) solve();

}
