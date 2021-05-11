#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp;
vector<pair<int, int>> sizes;
vector<int> path;

int stackSize(int idx) {
	if (dp[idx]) return dp[idx];
	for (int i = 0; i < sizes.size(); i++) {
		if (sizes[i].first > sizes[idx].first && sizes[i].second > sizes[idx].second) {
			int size = stackSize(i) + 1;
			if (size > dp[idx]) {
				dp[idx] = size;
				path[idx] = i;
			}
		}
	}
	return dp[idx];
}

void solve() {
	int n, w, h;
	cin >> n >> w >> h;
	
	dp.resize(n + 1);
	path.resize(n + 1);
	sizes.emplace_back(w, h);
	for (int i = 0; i < n; i++) {
		cin >> w >> h;
		sizes.emplace_back(w, h);
	}
	
	cout << stackSize(0) << endl;
	int p = 0;
	while (path[p]) {
		cout << path[p] << " ";
		p = path[p];
	}
	cout << endl;
}

int main() {
	solve();
}
