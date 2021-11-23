#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<ll> sums(n+2);
	for (int i = 2; i < n; i++) {
		sums[i] = sums[i-2] + a[i-2];
	}

}

int main() {
	int t; cin >> t;
	while (t--) solve();

}
