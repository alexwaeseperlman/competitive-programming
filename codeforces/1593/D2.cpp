#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2000000;
bitset<N> notPrime;
vector<int> primes;

set<int> factors(int n) {
	set<int> out;
	for (int i = 1; i*i <= n; i++) {
		if (n % i == 0) {
			out.insert(i);
			out.insert(n/i);
		}
	}
	return out;
}

int gcd(int a, int b) {
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(a%b, b);
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	map<int, int> counts;
	for (int i = 0; i < n; i++) counts[a[i]]++;

	bool l = false;
	for (auto [n, count] : counts) {
		if (count >= a.size()/2) {
			l = true;
		}
	}

	int high = 0;
	for (int i = 0; i < n; i++) {
		map<int, set<int>> factorPairs;
		for (int j = i+1; j < n; j++) {
			auto f = factors(abs(a[i] - a[j]));

			for (int k : f) {
				factorPairs[k].insert(j);
			}
		}

		for (auto [factor, count] : factorPairs) {
			if (factor > high && (count.size() + counts[a[i]]) >= n/2) high = factor;
		}
	}


	if (l) high = -1;
	cout << high << endl;
}

int main() {
	for (int i = 2; i < N; i++) {
		if (!notPrime[i]) {
			primes.push_back(i);
			for (int j = 2*i; j < N; j += i) {
				notPrime[j] = true;
			}
		}
	}
	int t; cin >> t;
	while (t--) solve();

}
