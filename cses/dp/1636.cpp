#include <bits/stdc++.h>
using namespace std;

// state -> value of coins
// value at that state -> number of ways to reach that state
// f(a, b) is the number of ways to reach value b with the first a coins
// f(n, x) = f(n, x-value[n]) + f(n-1, x)
int dp[1000001];
int main() {
	dp[0] = 1;
	int n, x; cin >> n >> x;

	vector<int> c(n);
	for (int i = 0; i < n; i++) cin >> c[i];

	for (int i = 0; i < n; i++) {
		for (int j = c[i]; j <= x; j++) {
			dp[j] = (dp[j-c[i]] + dp[j]) % 1000000007;
		}
	}

	cout << dp[x] << endl;
}
