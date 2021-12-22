#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
	ll N; cin >> N;
	vector<ll> p(N+2), t(N+2), d(N+2);
	for (ll i = 1; i <= N; i++) cin >> p[i];
	for (ll i = 1; i <= N; i++) cin >> t[i];
	for (ll i = 0; i <= N+1; i++) {
		d[i] = p[i] - t[i];
	}
	ll neg = 0, pos = 0;
	for (ll i = 0; i < d.size()-1; i++) {
		ll x = d[i+1] - d[i];
		if (x < 0) neg -= x;
		else pos += x;
	}
	cout << max(neg, pos) << endl;
}
