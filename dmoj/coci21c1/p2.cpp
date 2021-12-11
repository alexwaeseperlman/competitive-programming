#include <bits/stdc++.h>
using namespace std;
using ll = int;

// state -> maximum number of rounds for a, max rounds for b
// dimensions:
// whos turn it is, start, end (exclusive), red pebbles, outcomes
ll dp[2][350][351][351];
string s;

int main() {
	ll n, k; cin >> n >> k;
	cin >> s;

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < k; j++) {
			dp[0][i][i+1][j] = numeric_limits<int>::max();
			dp[1][i][i+1][j] = numeric_limits<int>::max();
		}
		if (s[i] == 'C') {
			dp[0][i][i+1][k-1] = 1;
		}
	}

	for (ll size = 2; size <= n; size++) {
		for (ll i = 0; i < n-size; i++) {
			for (ll turn : {0, 1}) {
				for (ll red = 0; red < k; red++) {
					ll left = red + (s[i] == 'C'), 
						right = red + (s[i+size-1] == 'C');

					ll leftMoves = dp[!turn][i+1][i+size][left],
						rightMoves = dp[!turn][i][i+size-1][right];

					ll best = max(leftMoves, rightMoves);

					dp[turn][i][i+size][red] = max(best, best+1);
				}
			}
		}
	}

	ll res = dp[0][0][n][0];
	cout << dp[0][0][n][0] << " " << dp[0][0][n][0] << endl;
	if (res > dp[1][0][n][0]) cout << "DA" << endl;
	else cout <<"NE" << endl;

}
