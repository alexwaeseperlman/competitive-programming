#include <bits/stdc++.h>
#include "../../algorithms/modular_arithmetic.h"
using namespace std;
using namespace number_theory;
using ull = unsigned long long;

const int N = 100000000;
bitset<N> notPrime;
vector<ull> primes;
vector<vector<int>> primeFactors(N);

int main() {
	ull sum = 0;
	for (ull i = 2; i < N; i++) {
		if (!notPrime[i]) {
			primes.push_back(i);
			for (ull j = i; j < N; j+=i) {
				notPrime[j] = true;
				primeFactors[j].push_back(i);
			}
			notPrime[i] = false;
		}
		//cout << i << endl;
	}
	//cout << "Done sieve" << endl;

	for (int i = 1, p=0; p=primes[i], primes[i] < N && i < primes.size(); i++) {
		mod_int base(5, p), inv2(2, p);
		inv2 = inv2.inverse();

		if (!base.is_residue()) continue;
		
		mod_int sqrt = base.sqrt();
		//cout << p << " " << sqrt << endl;

		for (mod_int b : {(sqrt+1)*inv2, (-sqrt+1)*inv2}) {
			bool bad = false;

			for (int i : primeFactors[p-1]) {
				if (b.pow((p-1)/i) == 1) {
					bad = true;
					break;
				}
			}

			if (!bad && !((b*b) == b) && b.pow(p-1) == 1) {
				//sum+=p;
				//cout << p << " " << b << endl;
				sum+=p;
				break;
			}
		}
	}
	
	cout << sum+5 << endl;
}
