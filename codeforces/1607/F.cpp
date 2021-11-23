//#pragma GCC optimize "trapv" 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using namespace __gnu_pbds;

#define print(x) cout << #x << " " << x << endl;
#define print_array(x) (cout << #x); for (auto i : (x)) cout << " " << i; cout << endl;

template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ull gcd(ull a, ull b) {
	if (b > a) return gcd(a, b);
	if (b == 0) return a;
	return gcd(b, a%b);
}

char board[2000][2000];
int msteps[2000][2000];
bool visited[2000][2000];

void solve() {
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			msteps[i][j] = 1;
			visited[i][j] = false;
		}
	}

	auto inBounds = [&](pair<int, int> x) -> bool {
		return x.first >= 0 && x.first < n && x.second >= 0 && x.second < m;
	};

	priority_queue<pair<int, pair<int, int>>> q;

	for (int i = 0; i < n; i++) {
		if (board[i][0] == 'L') q.emplace(-1, pair<int,int>{i, 0});
		if (board[i][m-1] == 'R') q.emplace(-1, pair<int,int>{i, m-1});
	}
	for (int i = 0; i < m; i++) {
		if (board[0][i] == 'U') q.emplace(-1, pair<int,int>{0, i});
		if (board[n-1][i] == 'D') q.emplace(-1, pair<int,int>{n-1, i});
	}

	pair<int, int> best;
	int bsteps = 0;
	while (q.size()) {
		auto top = q.top();
		if (bsteps > top.first) {
			bsteps = top.first;
			best = top.second;
		}
		cout << top.first << " " << top.second.first << "," << top.second.second << endl;
		visited[top.second.first][top.second.second] = true;
		q.pop();
		for (pair<int, int> a : (pair<int, int>[]){ {0, -1}, {0, 1}, {1, 0}, {-1, 0} }) {
			pair<int, int> c = {top.second.first + a.first, top.second.second + a.second};
			if (inBounds(c)) {
				if (!visited[c.first][c.second]) {
					if (a == pair<int, int>{0, -1} && board[c.first][c.second] == 'L'
					 || a == pair<int, int>{0, 1} && board[c.first][c.second] == 'R'
					 || a == pair<int, int>{1, 0} && board[c.first][c.second] == 'U'
					 || a == pair<int, int>{-1, 0} && board[c.first][c.second] == 'D') {
						q.emplace(top.first - 1, c);
					}

				}
			}
		}
	}
	cout << best.second + 1 << " " << best.first + 1 << " " << -bsteps << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) solve();

}
