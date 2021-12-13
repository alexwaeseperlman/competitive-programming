#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"
#include <bits/stdc++.h>
using namespace std;
const int N = 7;

//vector<string> paths;
int total = 0;

struct direction {
	int x, y;
	char name;
} directions[4] = { { 1, 0, 'D' }, { -1, 0, 'U' }, { 0, -1, 'L' }, { 0, 1, 'R' } };

bool inBoard(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < N;
}


bitset<N> board[N];

bool blocked(int x, int y) {
	return !inBoard(x, y) || board[x][y];
}

string path = "";
void getPaths(int x, int y, direction prev, int depth) {
	if (x == N-1 && y == 0) {
		if (depth < N*N-1) return;
		//paths.push_back(path);
		total++;
		return;
	}
	if (blocked(x+prev.x, y+prev.y)) {
		int count = 0;
		for (direction i : directions) {
			if (blocked(x+i.x, y+i.y)) count++;
		}
		if (count == 2) return;
	}
	board[x][y] = true;
	for (direction i : directions) {
		if (path[depth] != '?' && path[depth] != i.name) continue;
		//bool set = path[depth] == '?';
		if (!blocked(i.x+x, i.y+y)) {
			//path[depth] = i.name;
			getPaths(i.x+x, i.y+y, i, depth+1);
			//if (set) path[depth] = '?';
		}
	}
	board[x][y] = false;
}


int main() {
	cin >> path;
	getPaths(0, 0, directions[0], 0);
	cout << total << endl;
}
