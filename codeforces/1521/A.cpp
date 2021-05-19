#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bitset<1000005> composite;
vector<ull> primes;

void genPrimes() {
	for (ll i = 2; i < 1000005; i++) {
		if (!composite[i]) {
			primes.push_back(i);
			for (ll j = i * 2; j < 1000005; j += i) composite[j] = true;
		}
	}
}

int main() {
	//genPrimes();
	ll t; cin >> t;
	while (t--) {
		ull a, b; cin >> a >> b;

		if (b == 1) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;

		cout << a * (b * 8 - 1) << " " << a <<  " " << a * b * 8 << endl;
	}
}
