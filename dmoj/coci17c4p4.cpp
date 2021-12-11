#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

bitset<5002> team;
int dp[5002][5002];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		team[i] = c == 1;
	}

	auto win = [&](int start, int a) -> bool {
		int r = dp[min(start+1, m)][(a+1)%n];
		return ((team[a] == team[(a+1)%n]) ? 0 : min(k, m-start)) != r;
	};

	for (int i = m; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = dp[i+1][j] + win(i, j);
			if (i+k+1 <= m) dp[i][j] -= win(i+k, j);
		}
	}	

	for (int i = 0; i < n; i++) {
		cout << (win(1, i) == team[i]) << " ";
	}
	cout << endl;
}
