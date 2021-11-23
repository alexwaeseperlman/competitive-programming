#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll triangle[3001][3001] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, k; cin >> n >> k;

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j <= i; j++) cin >> triangle[i][j];
	}

	ll s = 1;
	while (s < k) {
		ll d = min(k-s, (s+2)/3);
		for (ll i = 0; i <= n-s; i++) {
			for (ll j = 0; j <= i; j++) {
				triangle[i][j] = max(triangle[i][j], max(triangle[i+d][j], triangle[i+d][j+d]));
			}
		}
		s += d;
	}

	unsigned long long sum = 0;
	for (ll i = 0; i <= n-k; i++) {
		for (ll j = 0; j <= i; j++) {
			sum += triangle[i][j];
		}
	}

	cout << sum << endl;
}
