#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n, l, r, k; cin >> n >> l >> r >> k;
	vector<ll> a(n); for (ll i = 0; i < n; i++) cin >> a[i];

	sort(a.begin(), a.end());

	ll total = 0;
	for (ll i : a) {
		if (i >= l && i <= r) {
			if (k >= i) {
				k -= i;
				total++;
			}
		}
	}
	cout << total << endl;
}
int main() {
	int t; cin >> t;
	while (t--) solve();

}
