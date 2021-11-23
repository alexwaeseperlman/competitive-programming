#include <bits/stdc++.h>
using namespace std;
using ull = long long;

ull good(ull n, ull m) {
	vector<ull> dp(n+1, 0);
	ull total = 1, dtotal = 0;
	dp[1] = 1;

	for (ull i = 2; i <= n; i++) {
		dtotal += dp[i]+1;
		dp[i] = (dtotal + total) % m;

		for (ull j = 2*i; j <= n; j+=i) {
			dp[j] += dp[i] - dp[i-1];
		}

		total = (total+dp[i]) % m;
	}

	return dp[n];
}

int main() {
	ull n, m; cin >> n >> m;
	cout << good(n, m) << endl;
}
