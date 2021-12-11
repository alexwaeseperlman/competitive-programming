#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

char board[1000][1000];
int n, m;

pi diffs[] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}


	set<pair<pi, pi>> g;
	int sat = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'G') {
				int cows = 0;
				vector<pi> adj;
				for (auto [x, y] : diffs) {
					if (i+x >= 0 && i+x < n && j+y >= 0 && j+y < m) {
						if (board[i+x][j+y] == 'C') adj.emplace_back(i+x, j+y);
					}
				}
				int pairs = (adj.size()*(adj.size()-1))/2;
				
				if (adj.size() >= 2) {
					for (int x = 0; x < adj.size()-1; x++) {
						for (int y = x+1; y < adj.size(); y++) {
							pairs -= g.count(minmax(adj[x], adj[y]));
						}
					}

					sat+= pairs>0;

				}
				if (adj.size() == 2) {
					g.insert(minmax(adj[0], adj[1]));
				}
			}
		}
	}


	cout << sat << endl;
}
