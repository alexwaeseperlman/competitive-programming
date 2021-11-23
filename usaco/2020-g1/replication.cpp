#include <bits/stdc++.h>
using namespace std;

int N, D;
char board[1000][1000];
struct v2i {
	int x, y;
	v2i(int x, int y): x(x), y(y) {}
};

stack<v2i> robots;
vector<vector<bool>> reachable;

bool oob(int x, int y) {
	return x < 0 || y < 0 || x >= N || y >= N || board[x][y] == '#' ;
}

void simulate(v2i direction, v2i start) {
	v2i pos = start;
	int steps = 0;

	v2i perp = (direction.x != 0) ? v2i(0, 1) : v2i(1, 0);

	while (true) {
		for (int size : { (steps-1)/D, (steps)/D }) {
			bool add = false;
	add:
			for (int i = 0; i <= size; i++) {
				v2i p1 = v2i(direction.x*(steps-i+size)+start.x, direction.y*(steps-i+size)+start.y);
				v2i p2 = p1;
				p1.x += perp.x*i;
				p1.y += perp.y*i;
				p2.x -= perp.x*i;
				p2.y -= perp.y*i;

				if (oob(p1.x, p1.y) || oob(p2.x, p2.y)) {
					return;
				}
				if (add) {
					reachable[p1.x][p1.y] = true;
					reachable[p2.x][p2.y] = true;
					board[p1.x][p1.y] = steps+'a';
					board[p2.x][p2.y] = steps+'a';
				}
			}
			if (!add) {
				add = true;
				goto add;
			}
		}
		steps++;
	}

}

int main() {
	cin >> N >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'S') robots.emplace(i, j);
		}
		reachable.push_back(vector<bool>(N));
	}

	while (robots.size()) {
		for (v2i direction : (v2i[]){ {0, 1}, {0, -1}, {-1, 0}, {1, 0} }) simulate(direction, robots.top());
		robots.pop();
	}
	int total = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			total += reachable[i][j];
		}
	}

	//for (int i = 0; i < N; i++) {
		//for (int j = 0; j < N; j++) {
			//cout << board[i][j];
		//}
		//cout << endl;
	//}
	cout << total << endl;
}
