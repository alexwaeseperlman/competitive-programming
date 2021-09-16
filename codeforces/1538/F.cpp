#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
	ull t; cin >> t;
	while (t--) {
		ull l, r; cin >> l >> r;
		ull diff = r - l;
		ull total = 0;
		for (ull i = 1; i <= r; i *= 10) {
			total += (diff + l % i) / i;
		}

		cout << total << endl;
	}
}
