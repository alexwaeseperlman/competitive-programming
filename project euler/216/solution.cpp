#include <bits/stdc++.h>
#include "../../algorithms/modular_arithmetic.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using namespace number_theory;
const ll N = 50000000;
const ll primeN = (N/2) * 3;
bitset<primeN+1> notPrime;
bitset<N+1> compositeSquares;
vector<ll> primes;

int main() {
	notPrime[1] = true;
	for (ll i = 2; i <= primeN; i++) {
		if (!notPrime[i]) {
			primes.push_back(i);
			for (ll j = i * 2; j <= primeN; j+=i) {
				notPrime[j] = true;
			}
		}
	}

	cout << "primes done" << endl;
	ll total = N-1;
	int c = 0;
	for (ull i = 1; i < primes.size(); i++) {
		mod_int sqrt = mod_int(2, primes[i]);
		if (sqrt.is_residue()) {
			if (i % 10000 == 0) cout << primes[i] << endl;
			sqrt = sqrt.sqrt();
			mod_int inverse = sqrt.inverse();
			for (mod_int s : {inverse, -inverse}) {
				for (ll j = s.get_val(); j <= N; j += primes[i]) {
					if (2*j*j-1 == primes[i]) continue;
					//cout << "removing " << 2*j*j -1 << " because " << s << " " << primes[i] << endl;
					if (!compositeSquares[j]) total--;
					compositeSquares[j] = true;
				}
			}
		}
	}
	cout << total << endl;
}
