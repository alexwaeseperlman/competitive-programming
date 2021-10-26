#include <bits/stdc++.h>
using namespace std;

void solve() {

	int n; cin >> n;

	unsigned long long zeros = 0, ones = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x == 0) zeros++;
		if (x == 1) ones++;
	}
	unsigned long long total = (1ull<<zeros) * ones;
	cout << total << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
