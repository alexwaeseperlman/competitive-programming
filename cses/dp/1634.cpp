#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

int best[2000001];
int main() {
	fill(best, best+2000001, numeric_limits<int>::max()-1);
	int n, x; cin >> n >> x;
	vector<int> c(n);
	for (int i = 0; i < n; i++) cin >> c[i];

	best[0] = 0;
	int steps = 0;
	while (best[x] == numeric_limits<int>::max()-1) {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < n; j++) {
				best[i+c[j]] = min(best[i+c[j]], best[i]+1);
			}
		}
		steps++;
		if (steps > 1000000) break;
	}

	if (best[x] < 10000000) cout << best[x] << endl;
	else cout << -1 << endl;



}
