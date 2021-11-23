#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

struct state {
	bool red = false;
	state *pstate = 0;
	bool reachable = false;
};

void solve() {
	int n, a, b; cin >> n >> a >> b;
	string s; cin >> s;

	vector<vector<vector<vector<state>>>> dp(n+1, vector<vector<vector<state>>>(n+1, vector<vector<state>>(a, vector<state>(b))));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k < a; k++) {
				for (int l = 0; l < b; l++) {
					if (dp[i][j][k][l].reachable || (i == 0 && k == 0 && l == 0)) {
						int R = (k * 10 + (s[i]-'0')) % a,
							B = (l * 10 + (s[i]-'0')) % b;
						dp[i+1][j+1][R][l] = { true, &dp[i][j][k][l], true };
						dp[i+1][j][k][B] = {false, &dp[i][j][k][l], true };
					}
				}
			}
		}
	}

	int minDiff = numeric_limits<int>::max();
	state best;
	for (int i = 1; i < n; i++) {
		if (dp[n][i][0][0].reachable && abs(n-2*i) < minDiff) {
			minDiff = abs(n-2*i);
			best = dp[n][i][0][0];
		}
	}
	if (!best.reachable) {
		cout << "-1" << endl;
		return;
	}

	string out = "";
	while (best.pstate) {
		out = (best.red ? "R" : "B") + out;
		best = *best.pstate;
	}
	cout << out << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();

}

