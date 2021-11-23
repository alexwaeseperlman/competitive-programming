#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n; cin >> m >> n;

	vector<vector<int>> grid(m, vector<int>(n));
	vector<set<pair<int, int>>> positions(n*m+1);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] <= m*n) positions[grid[i][j]].emplace(i, j);
		}
	}

	vector<vector<bool>> visited(m, vector<bool>(n));
	queue<pair<int, int>> pos;
	pos.emplace(m-1, n-1);
	while (pos.size()) {
		auto [i, j] = pos.front();
		pos.pop();
		if (visited[i][j]) continue;
		visited[i][j] = true;

		for (pair<int, int> x : positions[(i+1)*(j+1)]) {
			if (!visited[x.first][x.second]) pos.emplace(x.first, x.second);
		}
		positions[(i+1)*(j+1)].clear();
	}

	if (visited[0][0]) cout << "yes" << endl;
	else cout << "no" << endl;
}
