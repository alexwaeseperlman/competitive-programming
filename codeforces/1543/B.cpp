#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

void solve() {
	ull n; cin >> n;
	ull sum = 0;
	for (ull i = 0; i < n; i++) {
		ull x; cin >> x;
		sum += x;
	}

	ull score = (sum % n) * (n - (sum % n));
	cout << score << endl;
}

int main() {
	cin.tie(0);

	int t; cin >> t;
	while (t--) solve();

}
