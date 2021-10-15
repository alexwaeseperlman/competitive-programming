#include <bits/stdc++.h>
#include <limits>

using namespace std;

void solve() {
	int n, k; cin >> n >> k;

	vector<set<int>> edges(n+1);
	set<int> oneEdge;
	for (int i = 1; i <= n; i++) oneEdge.insert(i);
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;

		edges[u].insert(v);
		edges[v].insert(u);

		if (edges[u].size() > 1) oneEdge.erase(u);
		if (edges[v].size() > 1) oneEdge.erase(v);
	}

	queue<int> bfs;
	vector<bool> visited(n+1), leaf(n+1);
	vector<int> layers(n+1, 0);

	for (int i : oneEdge) {
		bfs.push(i);
		layers[i] = 1;
		leaf[i] = 1;
	}

	while (bfs.size()) {
		int top = bfs.front();
		bfs.pop();
		if (visited[top]) continue;

		visited[top] = true;

		for (int i : edges[top]) {
			edges[i].erase(top);
			if (!visited[i] && edges[i].size() == 1) {
				layers[i] = layers[top]+1;
				bfs.push(i);
			}
		}
	}

	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (layers[i] <= k || (k && leaf[i])) c++;
		//cout << (leaf[i] ? 1 : layers[i]) << " ";
	}
	//cout << endl;

	cout << n - c << endl;

}

int main() {
	int t; cin >> t;
	while (t--) solve();

}
