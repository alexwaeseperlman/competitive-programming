#include <bits/stdc++.h>

using namespace std;
using ll = long long;

set<ll> primes;
bitset<100005> primeMask;

void fillPrimes(ll n) {
	for (ll i = 2; i <= n; i++) {
		if (!primeMask[i]) primes.insert(i);
		for (ll j = i; j <= n; j += i) {
			primeMask[j] = true;
		}
	}
}

int main() {
	ll n, q;

	fillPrimes(100001);
	for (ll i : primes) cout << i << endl;

	vector<set<int>> factors;

	for (ll i = 0; i < n; i++) {
		ll a; cin >> a;

		for (ll prime : primes) {
			if (a % prime == 0) factors[i].insert(prime);
		}
	}
}

