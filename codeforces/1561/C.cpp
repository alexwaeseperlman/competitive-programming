#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<vector<int>> a(n);
	vector<pair<int, int>> m(n);
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		a[i] = vector<int>(k);
		int power = numeric_limits<int>::lowest();
		for (int j = 0; j < k; j++) {
			cin >> a[i][j];
			a[i][j] -= j;
			power = max(power, a[i][j]);
		}
		m[i] = {power, i};
	}

	sort(m.begin(), m.end());

	int total = 0, start = 0;
	for (int i = 0; i < n; i++) {
		start = max(start, m[i].first - total+1);
		
		total += a[m[i].second].size();
	}

	cout << start << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
