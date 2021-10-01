#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const ull N = 10000000, familySize=8;

bitset<N> notPrime;
set<ull> primes;

vector<set<ull>> families(1<<(familySize+1));

int main() {
	for (int i = 2; i < N; i++) {
		if (!notPrime[i]) {
			for (ull j = 2*i; j < N; j += i) notPrime[j] = true;
			primes.insert(i);
		}
	}

	ull low = numeric_limits<ull>::max(), lowMask = 0;
	for (ull digs = 6; digs < 7; digs++) {
		for (ull sameMask = 0; sameMask < 1<<digs; sameMask++) {
			auto i = primes.lower_bound(pow(10, digs-1)), ub = primes.upper_bound(pow(10, digs));

			for (; i != ub; i++) {
				ull count = 0;
				for (ull replacement = 0; replacement <= 9; replacement++) {
					if (replacement == 0 && ((1 << (digs-1)) & sameMask)) continue;
					ull num = 0, mp = 1;
					ull p = *i;
					while (p) {
						num *= 10;
						if (sameMask & mp) {
							num += replacement;
						}
						else {
							num += p % 10;
						}
						p /= 10;
						mp <<= 1;
					}

					ull x = 0;
					while (num) {
						x *= 10;
						x += num % 10;
						num /= 10;
					}
					if (replacement == 0 && sameMask & 1) x *= 10;

					if (x > 0 && x < N && !notPrime[x]){
						count++;
					}
				}
				if (count == 8){
					cout << *i << " " << bitset<familySize>(sameMask) << endl;
					if (*i < low) {
						low = *i;
						lowMask = sameMask;
					}
				}
			}
		}
	}
	cout << low << " " << bitset<familySize>(lowMask) << endl;
}
