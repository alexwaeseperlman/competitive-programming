#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

vector<vector<int>> dp, triangle;

int main() {
	int n; cin >> n;

	dp.reserve(n);
	triangle.reserve(n);
	for (int i = 0; i < n; i++) {
		triangle[i].resize(i+1);
		dp[i].resize(i+1);
		for (int j = 0; j <= i; j++) cin >> triangle[i][j];
	}

	for (int j = 0; j <= n; j++) {
		dp[n-1][j] = triangle[n-1][j];
	}

	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			dp[i-1][j] = triangle[i-1][j] + max(dp[i][j], dp[i][j+1]);
		}
	}

	cout << dp[0][0] << endl;

}
