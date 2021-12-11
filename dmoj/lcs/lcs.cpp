#include <bits/stdc++.h>
using namespace std;

// f(a, b) is the length of the longest common subsequence up until index a in the first array, and index b in the second array
// f(x, 0) = f(0, y) = 0
int dp[1001][1001];

pair<int, int> previous[1001][1001];

int main() {
	int N, M; cin >> N >> M;

	vector<int> a(N), b(M);
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < M; i++) cin >> b[i];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (dp[i][j-1] > dp[i-1][j]) {
				dp[i][j] = dp[i][j-1];
				previous[i][j] = {i, j-1};
			}
			else {
				dp[i][j] = dp[i-1][j];
				previous[i][j] = {i-1, j};
			}
			if (a[i-1] == b[j-1] && dp[i-1][j-1]+1 > dp[i][j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				previous[i][j] = {i-1, j-1};
			}
		}
	}

	vector<int> path;
	int i = N, j = M;
	while (i || j) {
		if (previous[i][j] == pair<int, int>(i-1, j-1)) path.push_back(a[i-1]);
		auto p = previous[i][j];
		i = p.first;
		j = p.second;
	}

	for (int i = path.size()-1; i >= 0; i--) {
		cout << path[i] << " ";
	}
	cout << endl;
	cout << dp[N][M] << endl;
}
