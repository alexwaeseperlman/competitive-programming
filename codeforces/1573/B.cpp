#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	vector<int> ap(n), bp(n);

	for (int i = 0; i < n; i++) {
		ap[(a[i]-1)/2] = i;
		bp[(b[i]-2)/2] = i;
	}

	int low = n;
	int steps = n;
	for (int i = 2; i <= 2*n; i+=2) {
		low = min(low, ap[(i - 1)/2]);
		if (low + bp[(i-2)/2] < steps) steps = low + bp[(i-2)/2];
	}
	cout << steps << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
