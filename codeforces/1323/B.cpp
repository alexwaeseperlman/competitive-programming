#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n, m, k; cin >> n >> m >> k;
	map<ll, ll> factors;
	for (ll i = 1; i <= sqrt(k); i++) {
		if (k%i == 0) {
			factors.emplace(i, k/i);
			factors.emplace(k/i, i);
		}
	}

	auto regions = [&](ll size) -> map<ll, ll> {
		map<ll, ll> out;
		ll p = 0, start = 0;
		for (ll i = 0; i <= size; i++) {
			ll x; 
			if (i < size) cin >> x;
			else x = 0;
			if (x && x != p) start = i;

			if (!x && p) {
				for (auto [f, d] : factors) {
					if (i - start >= f) {
						out[f] += i-start-f+1;
					}
				}
			}
			p=x;
		}
		return out;
	};
	map<ll, ll> ar = regions(n), br = regions(m);
	ll total = 0;
	for (auto [i, c] : ar) {
		total += c*br[factors[i]];
	}
	cout << total << endl;
}
