#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

void solve() {
	ull a, b; cin >> a >> b;
	if (a == b) {
		cout << 0 << " " << 0 << endl;
		return;
	}
	ull h = max(a,b), l = min(a,b);
	ull gcd = h - l;

	cout << gcd << " " << min(l%gcd, gcd-(l%gcd)) << endl;
	
}

int main() {
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) solve();
}
