#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll N, K, L; cin >> N >> K >> L;
	vector<ll> c(N), psum(N+1);
	for (ll i = 0; i < N; i++) cin >> c[i];
	sort(c.begin(), c.end());
	reverse(c.begin(), c.end());

	for (ll i = 1; i <= N; i++) {
		psum[i] = psum[i-1] + c[i-1];
	}

	ll best = 0;
	for (ll i = 1; i <= N; i++) {
		ll lb = 0, ub = N;
		while (lb < ub) {
			ll m = (ub+lb)/2;
			if (c[m] < i) ub = m;
			else lb = m+1;
		}

		if (c[i-1] >= i-K && (i*(i-lb)) - (psum[i] - psum[lb]) <= L*K) best = i;
	}
	cout << best << endl;
}
