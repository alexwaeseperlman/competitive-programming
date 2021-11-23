#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	bool even = false;
	int x = 0;
	while (!is_sorted(a.begin(), a.end())) {
		x++;
		for (int i = even; i < n - 1 - !even; i+=2) {
			if (a[i] > a[i+1]) swap(a[i], a[i+1]);
		}
		even = !even;
	}

	cout << x<< endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
