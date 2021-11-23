#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;

int dp[401][401];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));
	int n; cin >> n;
	// Rows -> start point
	// Columns -> end point
	// state -> max rice ball

	for (int i = 0; i < n; i++) {
		cin >> dp[i][i+1];
		dp[i][i] = 0;
	}

	for (int step = 2; step <= n; step++) {
		for (int i = 0; i <= n-step; i++) {
			for (int mid = 1; mid <= step; mid++) {
				for (int ms = 0; ms <= step-mid; ms++) {
					if (dp[i][i+mid] > -1 && dp[i][i+mid] == dp[i+mid+ms][i+step]) {
						if (dp[i+mid][i+mid+ms]==-1) continue;
						dp[i][i+step] = dp[i][i+mid]*2 + dp[i+mid][i+mid+ms];
					}
				}
			}
		}
	}
	int m = 0;
	for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) m = max(m, dp[i][j]);
	cout << m << endl;
}
