#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, Q;
	cin >> N >> M;
	vector<vector<char>> pool(N, vector<char>(M));

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> pool[i][j];

	cin >> Q;

	for (int _ = 0; _ < Q; _++) {
		int q; cin >> q;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (pool[i][j] == 'X') {
					pool[i][j] = '.';
					if (i+1 < N) pool[i+1][j] = 'X';
				}
			}
		}
	}

}
