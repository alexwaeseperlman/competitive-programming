#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;

int psum[513][513];
int dp[512][512][9];
pair<int, int> bp[512][512][9];
bitset<513> out[513];
bitset<513> board[513];

void fill(int ti, int tj, int s, bool c) {
	for (int i = 0; i < (1<<s); i++) {
		for (int j = 0; j < (1<<s); j++) {
			out[i+ti][j+tj] = c;
		}
	}
}

int wrong(int ti, int tj, int s, bool c) {
	int filled = psum[ti-1+(1<<s)][tj-1+(1<<s)] - psum[ti-1][tj+(1<<s)-1] - psum[ti+(1<<s)-1][tj-1] + psum[ti-1][tj-1];
	if (!c) return (1<<(s<<1)) - filled;
	else return filled;
}

void check(int ti, int tj, int s) {
	if (s == 0) {
		return;
	}
	vector<pair<int, int>> corners = { {ti, tj}, {ti+(1<<s-1), tj}, {ti, tj+(1<<s-1)}, {ti+(1<<s-1), tj+(1<<s-1)} };
	for (int i = 0; i < 4; i++) check(corners[i].first, corners[i].second, s-1);
	int best = numeric_limits<int>::max();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			for (int a = 0; a < 4; a++) {
				if (a == j || a == i) continue;
				int b = 6-a-i-j;
				int cost = wrong(corners[i].first, corners[i].second, s-1, 1) +
						wrong(corners[j].first, corners[j].second, s-1, 0) +
						dp[corners[a].first][corners[a].second][s-1] +
						dp[corners[b].first][corners[b].second][s-1];
				if (cost < best) {
					bp[ti][tj][s] = { i, j };
					best = cost;
				}
			}
		}
	}

	dp[ti][tj][s] = best;
}

void draw(int ti, int tj, int s) {
	if (s == 0) {
		fill(ti, tj, s, board[ti][tj]);
		return;
	}
	vector<pair<int, int>> corners = { {ti, tj}, {ti+(1<<s-1), tj}, {ti, tj+(1<<s-1)}, {ti+(1<<s-1), tj+(1<<s-1)} };
	for (int i = 0; i < 4; i++) {
		int x = corners[i].first, y = corners[i].second;
		if (i == bp[ti][tj][s].first) fill(x, y, s-1, 0);
		else if (i == bp[ti][tj][s].second) fill(x, y, s-1, 1);
		else draw(x, y, s-1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N; cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			char x; cin >> x;
			psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + (x == '1');
			board[i][j] = x == '1';
		}
	}

	check(1, 1, 31 - __builtin_clz(N|1));

	draw(1, 1, 31 - __builtin_clz(N|1));
	cout << dp[1][1][31-__builtin_clz(N|1)] << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << out[i][j];
		}
		cout << endl;
	}

}
