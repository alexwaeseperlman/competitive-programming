#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n; cin >> n;
	vector<ll> p(n);

	for (ll i = 0; i < n; i++) cin >> p[i];
	ll sum = 0, minDiff = numeric_limits<ll>::max();
	for (ll i : p) sum += i;
	
	for (ll m = 0; m < (1<<n); m++) {
		ll total = 0, i=0;
		for (ll k = 1; k <= m; k <<= 1) {
			if (m&k) total+=p[i];
			i++;
		}
		minDiff = min(minDiff, abs(sum-2*total));
	}

	cout << minDiff << endl;
}
