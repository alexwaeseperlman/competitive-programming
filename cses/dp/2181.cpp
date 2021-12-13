#include <bits/stdc++.h>
using namespace std;

bool valid(int n) {
	bool e = false;
	while (n) {
		if (n&1 && !e) e = true;
		else if (e && ~n&1) return false;
		else e = false;
	}
	return true;
}

int ex(int n, int p) {
	return ~n & ~p;
}



// dp[i][j] -> i is the number of rows
// j is a bitmask representing the tiling for the previous row
// Every one in this bitmask must be followed by another 1 (1x2 tiles take up two spaces)
// e.g. 011011 is a valid tiling for n=6
// Invalid values should contain a 0

int dp[1001][1<<10];
int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < 1<<n; i++) {
		dp[1][i] = valid(i);
	}
	for (int i = 2; i <= m; i++) {
		for (int j = 0; j < 1<<n; j++) {
			
		}
	}

}
