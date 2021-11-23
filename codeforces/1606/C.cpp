#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

void solve() {
	ull n, k; cin >> n >> k;
	vector<ull> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = pow(10, a[i]);
	}
	k++;


	function<ull(ull, ull, ull)> solve = [](ull k, ull base, ull max) -> ull {
		return min(max,k*base);
	};

	ull total = 0;

	for (int i = 0; i < n-1 && k; i++) {
		total += solve(k, a[i], a[i+1]-a[i]);
		k -= min((a[i+1]-a[i])/a[i], k);
	}

	total += solve(k, a[n-1], -1);

	cout << total << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
