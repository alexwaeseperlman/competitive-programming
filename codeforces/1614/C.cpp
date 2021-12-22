#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll base = 1000000007;

ll pow(ll n, ll p) {
	ll x = n, out = 1;
	while (p) {
		if (p&1) out = (out*x)%base;
		x = (x*x)%base;
		p>>=1;
	}
	return out;
}

void solve() {
	ll n, m; cin >> n >> m;

	vector<array<ll, 3>> a(m);

	for (ll i = 0; i < m; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}

	sort(a.begin(), a.end());
	
	vector<ll> o;

	for (ll i = 0; i < m; i++) {
		ll x = a[i][2];
		o.push_back(x);
	}
	ll total = 0;
	for (ll j = 1; j < 1<<30; j<<=1) {
		ll count = 0;
		for (ll i : o) {
			if (j&i) count++;
		}
		//total += (j)*(1<<(count-1))*(1<<(o.size()-count-1));
		if (count) total = ((((j%base)*pow(2ll, n-1))%base)+total)%base;
	}
	cout << total << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();

}
