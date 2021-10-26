#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b > a) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a%b);
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> bitCounts(31);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 30; j++) {
			if (a[i] & (1<<j)) bitCounts[j]++;
		}
	}

	int g = 0;
	for (int i = 0; i < bitCounts.size(); i++) {
		g = gcd(bitCounts[i], g);
	}

	for (int i = 1; i <= n; i++) {
		if (g % i == 0) cout << i << " ";
	}
	cout << endl;

}

int main() {
	int t; cin >> t;
	while (t--) solve();

}
