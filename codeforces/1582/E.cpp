#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	ll n; cin >> n;
	vector<ll> a(n);

	for (ll i = 0; i < n; i++) cin >> a[i];

	vector<ll> psum(n+1);

	for (ll i = 1; i <= n; i++) psum[i] = psum[i-1] + a[i-1];

	// First dimension -> start pos
	// Second dimension -> k value
	// value -> max sum
	vector<vector<ll>> dp(n, vector<ll>(2*sqrt(n)+1, numeric_limits<ll>::lowest()));
	dp[n-1][1] = a[n-1];

	for (int i = n-2; i >= 0; i--) {
		dp[i][1] = max(dp[i+1][1], a[i]);

	}

	int cutoff = 1;
	for (int k = 2; k <= 2*sqrt(n); k++) {
		cutoff += k;
		for (int i = n-cutoff; i >= 0; i--) {
			dp[i][k] = dp[i+1][k];
			if (psum[i+k]-psum[i] < dp[i+k][k-1]) {
				//cout << i << " " << k << " " << psum[i+k]-psum[i] << " " << dp[i+k][k-1] << endl;
				dp[i][k] = max(dp[i][k], psum[i+k]-psum[i]);
			}
		}
	}

	int best = 0;
	for (int i = 1; i < dp[0].size(); i++) {
		if (dp[0][i] < 0) break;
		best = i;
	}
	cout << best << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();

}
