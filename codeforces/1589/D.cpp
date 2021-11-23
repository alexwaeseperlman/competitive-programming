#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n; cin >> n;

	map<ll, ll> queries;
	auto query = [&](ll r) -> ll {
		if (queries.count(r)) return queries[r];
		cout << "? 1 " << r << endl;
		cout.flush();
		ll x; cin >> x;
		queries[r] = x;
		return x;
	};
	// binary search for upper bound
	ll lb = 1, ub = n+1;

	while (lb < ub) {
		ll m =(lb+ub)/2;
		if (query(m) < query(n)) lb = m+1;
		else ub = m;
	}
	ll k = lb;
	// The number of elements greater than a[k], before k
	ll diff = query(k) - query(k-1);
	ll j = k-diff;

	ll i = (j - (ll)sqrt(-4*j*j + 8*j*k + 4*j - 4*k*k - 4*k + 8*query(n) + 1)/2)-1;

	cout << "! " << i << " " << j << " " << k << endl;
	cout.flush();
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
