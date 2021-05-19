#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n; cin >> n;

	vector<ll> order(n);
	bool ordered = true;
	for (ll i = 0; i < n; i++) {
		cin >> order[i];
		ordered = ordered && (i+1) == order[i];
	}
	cout << !ordered + (order[0] == n && order[n-1] == 1) + (order[0] != 1 && order[n-1] != n) << endl;
}

int main() {
	ll n; cin >> n;
	while (n--) solve();
}
