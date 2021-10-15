#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(a%b, b);
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int g = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			g = gcd(abs(a[i] - a[j]), g);
		}
	}

	if (g == 0) g = -1;
	cout << g << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();

}
