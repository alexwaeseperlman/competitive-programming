#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (b > a) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a%b);
}

void solve() {
	int n; cin >> n;
	vector<ll> a(n), g(2);
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		g[i%2] = gcd(a[i], g[i%2]);
	}
	
	for (int par : {0, 1}) {
		bool works = true;
		for (int i = !par; i < n; i += 2) {
			if (a[i] % g[par] == 0) {
				works = false;
				break;
			}
		}
		if (works) {
			cout << g[par] << endl;
			return;
		}
	}

	cout << 0 << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
