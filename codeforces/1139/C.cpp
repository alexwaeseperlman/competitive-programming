#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll base = 1000000007;

ll modPow(ll n, ll p) {
	ll out = 1, x = n;
	for (ll i = 1; i <= p; i <<= 1) {
		if (p & i) out = (x*out)%base;
		x = (x*x)%base;
	}
	return out;
}

ll dsu[100001];
ll parent(ll x) {
	if (dsu[x] == x) return x;
	dsu[x] = parent(dsu[x]);
	return dsu[x];
}

void merge(ll a, ll b) {
	dsu[parent(a)] = parent(b);
}

int main() {
	ll n, k; cin >> n >> k;
	for (ll i = 0; i <= n; i++) dsu[i] = i;

	vector<pair<ll, ll>> edges;
	for (ll i = 0; i < n-1; i++) {
		ll u, v, x; cin >> u >> v >> x;
		if (x == 0) {
			merge(u, v);
		}
	}

	ll total = 0;
	map<int, int> counts;
	for (int i = 1; i <= n; i++) {
		counts[parent(i)]++;
	}

	for (auto [p, count] : counts) {
		total = (total + modPow(count, k))%base;
	}
	total = (modPow(n, k) + base - total)%base;

	cout << total << endl;
}
