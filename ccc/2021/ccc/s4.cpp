#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, W, D;
	cin >> N >> W >> D;

	vector<int> times(N+1, -1);
	vector<bool> visited(N+1);
	times[N] = 0;

	vector<vector<int>> walkways(N+1);
	for (int i = 0; i < W; i++) {
		int X, Y; cin >> X >> Y;
		walkways[Y].push_back(X);
	}

	queue<int> bfs;
	bfs.push(N);
	while (bfs.size()) {
		int top = bfs.front();
		bfs.pop();
		visited[top] = true;

		for (int i : walkways[top]) {
			times[i] = times[top]+1;
			if (!visited[i]) bfs.push(visited[i]);
			visited[i] = true;
		}
	}

	vector<int> route(N+1);
	for (int i = 1; i <= N; i++) cin >> route[i];


}
