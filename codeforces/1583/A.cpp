#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const ull N = 100000;
bitset<N> notPrime;

void solve() {
	ull n; cin >> n;

	vector<ull> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];



	ull sum = 0;
	for (int i = 0; i < n; i++) sum += a[i];

	bool done = false;
	ull best = 0, bi = -1, bj = -1, bk = -1;
	if (notPrime[sum]) {
		best = n;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = j; k < n; k++) {
				ull nsum = sum - a[i];
				if (j != i) nsum -= a[j];
				if (k != j) nsum -= a[k];

				if (notPrime[nsum]) {
					ull used = n - 1 - (i != j) - (j != k);
					if (used > best) {
						best = used;
						bi = i;
						bj = j;
						bk = k;
					}
				}

			}
		}
	}
	cout << best << endl;
	for (ull l = 0; l < n; l++) {
		if (l == bi || l == bj || l == bk) continue;
		cout << l + 1 << " ";
	}
	cout << endl;

}


int main() {

	for (ull i = 2; i < N; i++) {
		if (!notPrime[i]) for (ull j = 2*i; j < N; j+=i) {
			notPrime[j] = true;
		}
	}

	int t; cin >>  t;
	while (t--) solve();

}
