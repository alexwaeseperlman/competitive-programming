#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(m));
	vector<vector<int>> ops;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char a; cin >> a;
			board[i][j] = a == '1';
		}
	}

	auto update = [&](int i, int j) {
		int sum = 0;
		for (int x = i; x < i+2; x++) for (int y = j; y < j+2; y++) 
			sum += board[x][y];


		int tempBoard[2][2] = { { board[i][j], board[i][j+1] },
								{ board[i+1][j], board[i+1][j+1] } };

		vector<int> op;
		if (sum == 3 || sum == 4) {
			for (int x = i; x < i+2; x++) for (int y = j; y < j+2; y++) {
				if (board[x][y]) {
					op.push_back(x), op.push_back(y);
					tempBoard[x-i][y-j] = false;
				}
				if (op.size() == 6) goto b;
			}
		}
		else if (sum == 1 && op.size() == 0) {
			for (int x = i; x < i+2; x++) for (int y = j; y < j+2; y++)
				if (board[x][y]) {
					tempBoard[x-i][y-j] = false;
					op.push_back(x), op.push_back(y);
				}

			for (int x = i; x < i+2; x++) for (int y = j; y < j+2; y++)
				if (!board[x][y]) {
					tempBoard[x-i][y-j] = true;
					op.push_back(x), op.push_back(y);
					if (op.size() == 6) goto b;
				}
		}
		else if (op.size() == 0) {
			for (int x = i; x < i+2; x++) for (int y = j; y < j+2; y++)
				if (!board[x][y]) {
					tempBoard[x-i][y-j] = true;
					op.push_back(x), op.push_back(y);
				}

			for (int x = i; x < i+2; x++) for (int y = j; y < j+2; y++)
				if (board[x][y]) {
					tempBoard[x-i][y-j] = false;
					op.push_back(x), op.push_back(y);
					goto b;
				}
		}
b:
		board[i][j] = tempBoard[0][0];
		board[i][j+1] = tempBoard[0][1];
		board[i+1][j] = tempBoard[1][0];
		board[i+1][j+1] = tempBoard[1][1];
		return op;
	};


	auto sum = [&](int i, int j) {
		return board[i][j] + board[i][j+1] + board[i+1][j] + board[i+1][j+1];
	};
	auto fix = [&](int i, int j) {
		while (sum(i, j)) {
			ops.push_back(update(i, j));
		}
	};
	

	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m-1; j++) {
			fix(i, j);
		}
	}

	cout << ops.size() << endl;
	for (vector<int> &i : ops) {
		for (int x : i) cout << x+1 << " ";
		cout << endl;
	}
}

int main() {
	int t; cin >> t;
	while (t--) solve();

}
