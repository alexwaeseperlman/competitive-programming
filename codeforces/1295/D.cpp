#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 300000;
bitset<N> notPrime;
vector<ll> primes;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	if (b > a) return gcd(b, a);
	return gcd(b, a%b);
}

ll totient(ll n, ll ub) {
	set<ll> primeFactors;
	for (int i = 0; primes[i]*primes[i] <= n; i++) {
		if (n%primes[i] == 0) {
			primeFactors.insert(primes[i]);
			while (n % primes[i] == 0) n /= primes[i];
		}
	}
	if (n > 1) primeFactors.insert(n);

	for (ll i : primeFactors) {
		ub = ub - ((ub+i-1)/i);
	}

	return ub;
}

void solve() {
	ll a, m; cin >> a >> m;

	ll g = gcd(a, m);

	cout << totient(m/g, a/g+m/g) - totient(m/g, a/g) << endl;
}

int main() {
	for (ll i = 2; i < N; i++) {
		if (!notPrime[i]) {
			primes.push_back(i);
			for (ll j = 2*i; j < N; j+=i) {
				notPrime[j] = true;
			}
		}
	}

	ll t; cin >> t;
	while (t--) solve();
}
