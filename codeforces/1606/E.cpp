#pragma GCC optimize "trapv"
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ull = long long;
const ull base = 998244353;

ull pows[501][501];
ull modPow(ull n, ull k) {
	if (n <= 500 && k <= 500 && pows[n][k]) return pows[n][k];
	if (k == 0) return 1;
	ull p = 1, out = n % base;
	while (2*p <= k) {
		p*=2;
		out = (out*out)%base;
	}

	if (n <= 500 && k <= 500) {
		pows[n][k] = ((modPow(n, k-p))*out)%base;
		return pows[n][k];
	}
	return ((modPow(n, k-p))*out)%base;
}

ull chose[501][501];


ull dp[501][501];

void solve() {
	ull n, x; cin >> n >> x;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= x; j++) {
			dp[i][j] = modPow(min(i-1,j), i);
			if (j > i-1) for (int z = 2; z <= i; z++) {
				dp[i][j] = (dp[i][j] + (modPow(min(i-1,j), i-z)*chose[i][z]%base)*dp[z][j-i+1])%base;
			}
		}
	}
	cout << dp[n][x] << endl;
}

int main() {
	chose[0][0] = 1;
	for (int i = 1; i <= 500; i++) {
		chose[i][0] = 1;
		chose[i][i] = 1;
		for (int j = 1; j <= 500; j++) {
			chose[i][j] = (chose[i-1][j] + chose[i-1][j-1]) % base;
		}
	}


	solve();
}

