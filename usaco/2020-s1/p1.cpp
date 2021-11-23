#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	vector<set<int>> roads(N+1);
	for (int i = 0; i < N-1; i++) {
		int a, b; cin >> a >> b;
		roads[a].insert(b);
		roads[b].insert(a);
	}

	queue<int> bfs;
	int total = 0;
	bfs.push(1);
	while (bfs.size()) {
		int top = bfs.front();
		bfs.pop();
		for (int i : roads[top]) {
			bfs.push(i);
			roads[i].erase(top);
			total++;
		}
		int i = 1;
		while (i <= roads[top].size()) {
			i *= 2;
			total++;
		}
	}

	cout << total << endl;
}
