#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const ull N = 100000000;//00000;
vector<bool> notPrime(N+2);
//vector<vector<ull>> prime_factors(N+1);
vector<bool> doubleDivided(N+1);

int main() {
	for (ull i = 2; i <= N+1; i++) {
		if (!notPrime[i]) {
			for (ull j = 2*i; j <= N+1; j+=i) {
				notPrime[j] = true;
			}
		}
	}
	for (ull i = 2; i <= N; i++) {
		if (!notPrime[i]) {
			for (ull j = i; j <= N; j+=i) {
				if (notPrime[i+j/i]) {
					doubleDivided[j] = true;
				}
			}
		}
	}



	ull sum = 0;
	for (ull i = 1; i <= N; i++) {
		if (!doubleDivided[i]) {
			bool all = true;
			for (ull j = 1; j*j <= i; j++) {
				if (i % j == 0) all = all && !notPrime[j+i/j];
				if (!all) break;
			}
			if (all) sum += i;
		}
	}
	cout << sum << endl;
}
