#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, k; cin >> n >> k;
	vector<int> h(n+1);
	for (int i = 0; i < n+1; i++) {
		cin >> h[i];
	}

	vector<pair<int, int>> sh(n+1);
	for (int i = 0; i <= n; i++) sh[i] = { h[i], i };
	sort(sh.begin(), sh.end());

	vector<vector<int>> st(18, vector<int>(n+1));
	for (int i = 0; i <= n; i++) st[0][i] = sh[i].second;
	for (int i = 1; i < st.size(); i++) {
		for (int j = 0; j <= n; j++) {
			st[i][j] = max(st[i-1][j], st[i-1][min(j+(1<<(i-1)), n)]);
		}
	}
	vector<int> maxAfter(n+1);
	maxAfter[n] = sh[n].second;
	for (int i = 0; i < n; i++) {
		int size = log2(n-i);
		maxAfter[i] = max(st[size][i], st[size][n-(1<<size)]);
	}
	
	for (int i = 0; i < k; i++) {
		float incline; cin >> incline;

		for (int j = 0; j <= n; j++) {
			float minEnd = incline * 

			
		}

	}
}
