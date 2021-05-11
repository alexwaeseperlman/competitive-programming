#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n; cin >> n;
	vector<ll> values(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> values[i];
	}
	
	sort(values.begin(), values.end());
	vector<ll> counts(n+1, 0);
	
	ll total = 0;
	ll previous = values[0];
	ll count = 0;
	for (ll i = 0; i <= values.size(); i++) {
		if (i == values.size() || previous != values[i]) {
			counts[count]++, count = 0;
		}
		count++;
		if (i != values.size()) previous = values[i];
	}

	vector<ll> postsum(counts.size()+1, 0);
	ll k = 0; for (ll i = counts.size()-1; i >= 0; i--) k += counts[i], postsum[i] = k;

	ll small = n;
	for (ll i = 1; i < n+1 && postsum[i] > 0; i++) {
		ll moves = n - postsum[i]*i;
		small = min(moves, small);
	}
	cout << small << endl;

}

int main() {
	ll t; cin >> t;

	while (t--) solve();

}
