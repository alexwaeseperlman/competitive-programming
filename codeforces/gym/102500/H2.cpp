#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int> h(n+1);
	for (int i = 0; i <= n; i++) cin >> h[i];

	for (int x = 0; x < k; x++) {
		double slope; cin >> slope;
		vector<pair<double, int>> nh(n+1);
		for (int j = 0; j < n; j++) {
			nh[j].second = j;
			nh[j].first = h[j] - (j * 10) * slope;
		}

		sort(nh.begin(), nh.end());

		vector<vector<int>> st(18, vector<int>(n+1));
		for (int i = 0; i <= n; i++) st[0][i] = nh[i].second;
		for (int i = 1; i < st.size(); i++) {
			for (int j = 0; j <= n; j++) {
				st[i][j] = max(st[i-1][j], st[i-1][min(j+(1<<(i-1)), n)]);
			}
		}
		vector<int> maxAfter(n+1);
		maxAfter[n] = nh[n].second;
		for (int i = 0; i < n; i++) {
			int size = log2(n-i);
			maxAfter[i] = max(st[size][i], st[size][n-(1<<size)]);
		}

		int m = 0;
		for (int i = 0; i < n; i++) {
			m = max(maxAfter[i] - i, m);
		}
		cout << m << endl;
	}
	

}
