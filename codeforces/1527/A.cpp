#include <bits/stdc++.h>
using ull = unsigned long long;
using namespace std;

int main() {
	ull t; cin >> t;

	while (t--) {
		ull k; cin >> k;
		ull p = log2(k);

		cout << ((1 << p) - 1) << endl;
	}
}
