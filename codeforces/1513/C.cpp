#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using ll = long long;

ull dp[200001][10][10];
ull sums[200001][10];

void solve() {
	ull n, m; cin >> n >> m;
	
	ull sum = 0;
	while (n) {
		sum += sums[m][n % 10ull];
		n /= 10ull;
	}

	cout << sum % 1000000009ull << endl;
}

int main() {
	for (ull i = 0; i < 10; i++) {
		dp[0][i][i] = 1;
	}
	for (ull i = 1; i < 200001; i++) {
		for (ull j = 0; j < 10; j++) {
			for (ull k = 0; k < 9; k++) {
				dp[i][j][k+1] = dp[i-1][j][k];
			}
			dp[i][j][0] = dp[i][j][9];
			dp[i][j][1] += dp[i][j][9];
		}
	}

	for (ull i = 0; i < 200001; i++) {
		for (ull j = 0; j < 10; j++) {
			for (ull k = 0; k < 10; k++) {
				sums[i][j] += dp[i][j][k];
			}
		}
	}

	ull t; cin >> t;
	while (t--) solve();

}
