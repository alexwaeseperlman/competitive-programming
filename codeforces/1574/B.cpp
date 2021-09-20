#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	ll a, b, c, m; cin >> a >> b >> c >> m;

	ll minm = 2*max(max(a,b),c)-a-b-c-1, maxm = a + b + c - 3;

	cout << ((m >= minm && m <= maxm) ? "YES" : "NO") << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
