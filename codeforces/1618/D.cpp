#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a.begin(), a.end());
	
	long long total = 0;
	for (int i = 0; i < n-2*k; i++) {
		total += a[i];
	}
	for (int i = n-2*k; i < n-k; i++) {
		if (a[i] == a[i+k]) total++;
	}
	cout << total << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
