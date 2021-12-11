#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll base = 100000000;

bool valid(ll a, ll b) {
	return ((a & (a ^ (a >> 1)) & (a ^ (a << 1))) == a) && ((a&b) == 0);
}

ll dp[13][(1<<12)+1];
int main() {
	ll R, C; cin >> R >> C;
	vector<ll> rows(R+1);

	for (ll i = 1; i <= R; i++) {
		ll m = 1;
		for (ll j = 0; j < C; j++) {
			ll x; cin >> x;
			rows[i] <<= 1;
			rows[i] |= x;
			m <<= 1;
		}
	}

	dp[0][0] = 1;
	for (ll i = 1; i <= R; i++) {
		if (!rows[i]) {
			for (int j = 0; j < (1<<C); j++) {
				dp[i][j] = dp[i-1][j];
			}
			continue;
		}
		for (ll j = 0; j < (1<<C); j++) {
			ll mask = rows[i];
			if (valid(mask, j)) dp[i][mask] = (dp[i][mask]+dp[i-1][j])%base;
			do {
				mask = (mask-1)&rows[i];
				if (valid(mask, j)) {
					dp[i][mask] = (dp[i][mask]+dp[i-1][j])%base;
				}
			} while (mask);
		}
	}

	ll sum = 0;
	for (ll i = 0; i < (1<<C); i++) {
		sum = (sum+dp[R][i])%base;
	}
	cout << sum << endl;
}
