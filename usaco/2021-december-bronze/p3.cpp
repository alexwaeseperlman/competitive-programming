#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bitset<51> board[51];

void solve() {
	int N, K; cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c; cin >> c;
			board[i][j] = c == 'H';
		}
	}

	vector<vector<bool>> p;
	// direction: 0 right, 1 down
	function<ll(ll,ll,ll,ll)> paths = [&](ll x, ll y, ll moves, ll direction) -> ll {
		if (x >= N || y >= N) return 0;
		if (board[x][y]) return 0;
		if (x == N-1 && y == N-1) return 1;
		if (moves == 0) {
			if (x != N-1 && y != N-1) return 0;
			if (x == N-1 && direction == 0) return 0;
			if (y == N-1 && direction == 1) return 0;
		}
		return paths(x+1, y, moves - (direction == 1), 0) + paths(x, y+1, moves - (direction == 0), 1);
	};
	if (board[0][0]) cout << 0 << endl;
	else cout << paths(1, 0, K, 0) + paths(0, 1, K, 1) << endl;
}

int main() {
	int T; cin >> T;
	while (T--) solve();

}
