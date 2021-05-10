#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n, m; cin >> n >> m;

	vector<ll> a(n), x(m);
	for (ll i = 0; i < n; i++) cin >> a[i];
	for (ll i = 0; i < m; i++) cin >> x[i];

	ll sum = 0, high = 0;

	vector<pair<ll, ll>> psum(n);

	for (ll i = 0; i < n; i++) {
		sum += a[i];
		psum[i] = make_pair(sum, i);
		if (sum > high) high = sum;
	}
	sort(psum.begin(), psum.end());
	vector<ll> nsmallest_idx(n);
	ll smallest = n;
	for (ll i = n-1; i >= 0; i--) {
		if (psum[i].second <= smallest) smallest = psum[i].second;
		nsmallest_idx[i] = smallest;
	}
	ll hdiff = high - sum;

	for (ll i = 0; i < m; i++) {
		ll revos = sum <= 0 ? 0 : max((x[i]-1-hdiff) / sum, 0ll);

		ll currentSum = revos * sum;

		ll lb = 0, ub = n, j = n/2;
		while (ub - lb >= 1) {
			j = (lb + ub) / 2;
			if (psum[j].first + currentSum < x[i]) lb = j+1;
			else ub = j;
		}

		currentSum += psum[j].first;

		if (currentSum < x[i]) {
			cout << "-1" << " ";
			continue;
		}


		cout << nsmallest_idx[j] + revos * n << " ";
	}
	cout << endl;
}

int main() {
	ll t; cin >> t;
	while (t--) solve();

}
