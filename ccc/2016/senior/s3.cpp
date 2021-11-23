#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	int p1;

	vector<bool> pho(n), visited(n), phosub(n);
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		p1 = x;
		pho[x] = 1;
		phosub[x] = 1;
	}

	vector<int> dps(n, 0), v(n, 0);

	vector<vector<int>> edges(n);
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;

		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	queue<int> bfs;
	// start from the leaves
	for (int i = 0; i < n; i++) {
		if (edges[i].size() == 1) {
			bfs.push(i);
		}
	}

	int last = 0, lastNode = 0;
	while (bfs.size()) {
		const int t = bfs.front();
		bfs.pop();
		if (visited[t]) continue;

		int c = 0;
		for (int i : edges[t]) {
			v[i]++;
			if (!visited[i]) {
				if (edges[i].size() - v[i] <= 1) bfs.push(i);
			}
			else if (phosub[i] && visited[i]) {
				phosub[t] = true;
				dps[t] += dps[i] + 2;
				c++;
			}
		}
		visited[t] = true;
		if (pho[t] || c > 1) {
			last = dps[t];
			lastNode = t;
		}
	}

	// Find the deepest pho restaurant
	fill(visited.begin(), visited.end(), 0);
	stack<int> dfs;
	dfs.push(lastNode);
	vector<int> depth(n);

	while (dfs.size()) {
		int top = dfs.top();
		dfs.pop();
		if (visited[top]) continue;
		visited[top] = true;
		for (int i : edges[top]) {
			if (!visited[i]) {
				depth[i] = depth[top]+1;
				dfs.push(i);
			}
		}
	}

	int deepest = p1;

	for (int i = 0; i < n; i++) {
		if (pho[i] && depth[i] > depth[deepest]) {
			deepest = i;
		}
	}

	// Find the furthest pho restaurant from deepest
	int path = 0;
	fill(visited.begin(), visited.end(), 0);
	fill(depth.begin(), depth.end(), 0);
	dfs.push(deepest);
	while (dfs.size()) {
		int top = dfs.top();
		dfs.pop();
		if (visited[top]) continue;
		visited[top] = true;

		for (int i : edges[top]) {
			if (!visited[i]) {
				depth[i] = depth[top]+1;
				dfs.push(i);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (pho[i] && depth[i] > path) path = depth[i];
	}

	cout << last - path << endl;
}

