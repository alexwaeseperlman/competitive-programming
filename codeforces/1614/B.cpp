#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n; cin >> n;
	vector<pair<ll, ll>> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	vector<ll> out(n+1);
	sort(a.begin(), a.end());
	ll total = 0, base = 0, dist = 1;
	bool sign = 0;
	for (ll i = n-1; i >= 0; i--) {
		out[a[i].second+1] = dist * (sign?-1:1);
		total += dist*a[i].first;
		if (sign) dist++;
		sign = !sign;
	}
	cout << 2*total << endl;
	for (ll i : out) cout << i << " ";
	cout << endl;
}

int main() {
	ll t; cin >> t;
	while (t--) solve();
}
