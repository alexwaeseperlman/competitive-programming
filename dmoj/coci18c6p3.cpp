#include <bits/stdc++.h>
using namespace std;

int dp[501][2];
int main() {
	int n, m, k; cin >> n >> m >> k;

	vector<int> p(n+1), b(m+1);
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 0; i <= m; i++) cin >> b[i];

	int last = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m-p[i]; j++) {
			for (int x = 0; x <= k-j; x++) {
				dp[x+j][i&1] = max(dp[x][~i&1] + b[j+p[i]], dp[x+j][i&1]);
			}
		}
		last = dp[k][i&1];
	}

	cout << last << endl;
}
