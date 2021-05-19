#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
	ull n, k; cin >> n >> k;

	ull total = 1;

	for (ull i = 0; i < k; i++) {
		total *= n;
		total %= 1000000007;
	}

	cout << total << endl;
}

int main() {
	ll  t; cin >> t;

	while (t--) solve();
}
