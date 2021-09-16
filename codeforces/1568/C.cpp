#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

const ll base = 998244353;

ll factorial(ll n) {
	if (n == 0) return 1;
	return ((n % base) * factorial(n-1)) % base;
}

ll choose(ll n, ll k) {
	if (n - k < k) return choose(n, n-k);
	ll j = 1;
	ll o = 1;
	for (ll i = n-k+1; i <= n; i++) {
		if (j <= k) o = (o * i) / j++;
		else o = (o * i) % base;
	}
	return o % base;
}

void solve() {
	ll n; cin >> n;

	map<ll, ll> counts;
	for (ll i = 0; i < n; i++) {
		ll p; cin >> p;
		counts[p]++;
	}
	ll max = counts.rbegin()->first, smax = next(counts.rbegin())->first;
	if (counts[max] == 1 && max - smax > 1) {
		cout << 0 << endl;
		return;
	}
	if (counts[max] == 1 && smax != max) {
		if (n == 2) {
			cout << 1 << endl;
			return;
		}
		// Any combination works, as long as the highest comes before one of the second highest
		ll c = factorial(n-1-counts[smax]);
		ll a = 0;
		for (ll i = 0; i < n-counts[smax]; i++) {
			for (ll rside = 1; rside <= counts[smax]; rside++) {
				ll spaces = n-counts[smax]-i-1;
				a = a + (choose(spaces + rside, rside) * choose(i + counts[smax] - rside, counts[smax]-rside)) % base;
			}
		}

		a = ((a % base) * factorial(counts[smax]) % base) % base;
		c = (c*a)%base;
		cout << c << endl;

		return;
	}

	// Since there are two with the max, every combination is acceptable
	cout << factorial(n) << endl;
	return;
}
int main() { int t; cin >> t; while (t--) solve(); }
