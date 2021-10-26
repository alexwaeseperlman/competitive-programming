#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;


void solve() {
	int m, n; cin >> n >> m;
	vector<bool> hasRestrictions(n+1, false);

	for (int i = 0; i < m; i++) {
		int r = 0, _=0; cin >> _ >> r >> _;
		hasRestrictions[r] = true;
	}

	int noRestrictions = 0;
	for (int i = 1; i <= n; i++) if (!hasRestrictions[i]) noRestrictions = i;

	for (int i = 1; i <= n; i++) {
		if (i == noRestrictions) continue;

		cout << i << " " << noRestrictions << endl;
	}
}

int main() {
	int t; cin >>  t;
	while (t--) solve();

}
