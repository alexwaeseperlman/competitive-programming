#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m) {
	if (m == 0 || n == 0) return 0;
	if (m < 3 && n >= 3) return solve(m, n);
	if (n < 3 && m < 3) {
		return min(n, m);
	}
	int threes = m/3;
	return (threes)*n + solve(n, m-threes*3);
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		cout << min(solve(n, m), solve(m, n)) << endl;
	}

}
