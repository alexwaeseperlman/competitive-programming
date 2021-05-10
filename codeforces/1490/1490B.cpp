#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n; cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i] %= 3;
	}

	ll totals[3] = {0, 0, 0};
	for (ll i = 0; i < n; i++) {
		totals[arr[i]]++;
	}

	ll target = n / 3;
	ll out = 0;
	for (int i = 0; i < 6; i++) {
		if (totals[i%3] > target) {
			out += totals[i%3] - target;
			totals[(i+1)%3] += totals[i%3]-target;
			totals[i%3] = target;
		}
	}

	cout << out << endl;
}

int main() {
	ll t; cin >> t;
	while (t--) solve();
}
