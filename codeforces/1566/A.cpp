#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	ll n, s; cin >> n >> s;

	// first (n-1)/2 are 0s
	n -= (n-1)/2;

	cout << s/n << endl;
}

int main() {
	int t; cin >> t ;
	while (t--) solve();
}
