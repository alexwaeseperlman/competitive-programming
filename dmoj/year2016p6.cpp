#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

int dp[1024][1024], l[10], r[10];
bitset<1024> called[1024];
int L, R;
int lW[1024], rW[1024];

int bcount[1024];

void steps(int w, int lmask, int rmask) {
	//called[lmask][rmask] = true;
	int lon = bcount[lmask], ron = bcount[rmask];

	for (int mask = lmask; mask;) {
		mask = (mask-1)&lmask;
		if (abs(lW[mask] - rW[rmask]) <= w) {
			if (dp[lmask][rmask]+1 < dp[mask][rmask]) {
				dp[mask][rmask] = dp[lmask][rmask]+1;
				steps(w, mask, rmask);
			}
		}
	}
	for (int mask = rmask; mask;) {
		mask = (mask-1)&rmask;
		if (abs(rW[mask] - lW[lmask]) <= w) {
			if (dp[lmask][rmask]+1 < dp[lmask][mask]) {
				dp[lmask][mask] = dp[lmask][rmask]+1;
				steps(w, lmask, mask);
			}
		}
	}
}

int main() {
	int w; cin >> L >> R >> w;
	for (int i = 0; i < L; i++) cin >> l[i];
	for (int i = 0; i < R; i++) cin >> r[i];

	for (int i = 0; i < 1024; i++) {
		for (int j = 0; j < 1024; j++) {
			dp[i][j] = numeric_limits<int>::max()>>1;
		}
		bcount[i] = __builtin_popcount(i);
	}

	for (int mask = 0; mask < 1<<L; mask++) {
		int x = 0;
		for (int i = 1; i <= mask; i<<=1) {
			if (mask&i) lW[mask] += l[x];
			x++;
		}
	}
	for (int mask = 0; mask < 1<<R; mask++) {
		int x = 0;
		for (int i = 1; i <= mask; i<<=1) {
			if (mask&i) rW[mask] += r[x];
			x++;
		}
	}

	dp[(1<<L)-1][(1<<R)-1] = 0;

	steps(w, (1<<L)-1, (1<<R)-1);
	cout << dp[0][0] << endl;
}

