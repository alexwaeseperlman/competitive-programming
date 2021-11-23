#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;

	vector<vector<int>> rooms(n, vector<int>(m, -1)), walls(n, vector<int>(m));

	queue<pair<int, int>> bfs;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> walls[i][j];
			bfs.emplace(i, j);
		}
	}

	while (bfs.size()) {
		auto [i, j] = bfs.front();
		bfs.pop();
		if (rooms[i][j] > -1) continue;

		for (auto [mask, d] : (pair<int, pair<int, int>>[]){ { 0b0100, { 0, 1 } }, { 0b1000, {1, 0} }, { 0b0001, {0, -1} }, { 0b0010, {-1, 0 } } }) {
			if (i + d.first >= 0 && i + d.first < n && j + d.second >= 0 && j + d.second < m) {
				
			}
		}
	}




}
