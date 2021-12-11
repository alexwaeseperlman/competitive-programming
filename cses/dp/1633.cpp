#include <bits/stdc++.h>
using namespace std;

const int base = 1000000007;

int dp[2000000];

int main() {
	int n; cin >> n;
	dp[0] = 1;
	for (int i = 0; i < 1000000; i++) {
		for (int j = 1; j <= 6; j++) {
			dp[i+j] = (dp[i]+dp[i+j])%base;
		}
	}

	cout << dp[n] << endl;


}
