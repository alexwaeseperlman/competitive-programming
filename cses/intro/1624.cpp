#include <bits/stdc++.h>
using namespace std;

#define threatened 4
#define piece 2
#define blocked 1
#define empty 0

int board[8][8];

void place(int i, int j, bool on) {
	auto set = [&](int &x) -> void {
		if (on) x |= threatened;
		else x &= ~threatened;
	};
	if (on) board[i][j] |= piece;
	else board[i][j] &= ~piece;
	for (int x = 0; x < 8; x++) {
		set(board[i][x]);
		set(board[x][j]);
		if ((i-j) + x < 8 && (i-j)+x >= 0) set(board[i-j+x][x]);
		if (i - x+j < 8 && i-x+j >= 0) set(board[i-x+j][x]);
	}
}

void remove(int i, int j) {
	place(i, j, false);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (piece & board[i][j]) place(i, j, true);
		}
	}
}

void print() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (piece & board[i][j]) cout << "+";
				else if (blocked & board[i][j]) cout << "*";
				else if (threatened & board[i][j]) cout << "x";
				else cout << ".";
			}
			cout << endl;
		}
		cout << endl;
}

int count(int pieces, int top) {
	if (pieces == 0) {
		print();
		return 1;
	}
	if (top >= 8) return 0;
	int total = 0;
	for (int j = 0; j < 8; j++) {
		if (board[top][j] == empty) {
			place(top, j, true);
			total += count(pieces-1, top+1);
			remove(top, j);
		}
	}
	return total;
}

int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			char c; cin >> c;
			if (c == '*') board[i][j] = blocked;
		}
	}

	cout << count(8, 0) << endl;

	
}
