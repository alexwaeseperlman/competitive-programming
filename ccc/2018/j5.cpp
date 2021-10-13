#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main() {
	ull N; cin >> N;
	vector<set<ull>> edges(N);
	vector<bool> visited(N);
	vector<int> shortestPath(N, numeric_limits<int>::max());
	for (ull i = 0; i < N; i++) {
		ull m; cin >> m;
		while (m--) {
			ull x; cin >> x;
			edges[i].insert(x-1);
		}
	}

	priority_queue<pair<int, int>> search;
	int bestPath = numeric_limits<int>::max();
	search.emplace(-1, 0);
	shortestPath[0] = 1;
	while (search.size()) {
		auto [d, i] = search.top();
		search.pop();
		if (visited[i]) continue;
		visited[i] = true;
		d = -d;

		if (edges[i].size() == 0) {
			bestPath = min(bestPath, d);
		}

		for (ull e : edges[i]) {
			shortestPath[e] = min(shortestPath[e], d+1);
			if (!visited[e]) search.emplace(-shortestPath[e], e);
		}
	}

	bool all = true;
	for (int i = 0; i < visited.size(); i++) all = all && visited[i];
	cout << (all ? "Y" : "N") << endl << bestPath << endl;


}
