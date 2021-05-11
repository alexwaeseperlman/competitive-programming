#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n;
	cin >> n;

	int ra = -1, ca = -1, rb = -1, cb = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c == '*') {
				if (ra == -1 || ra == i) ra = i;
				else rb = i;
				if (ca == -1 || ca == j) ca = j;
				else cb = j;
			}
		}
	}

	if (rb == -1) rb = ra - 1 < 0 ? ra + 1 : ra - 1;
	if (cb == -1) cb = ca - 1 < 0 ? ca + 1 : ca - 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i == ra || i == rb) && (j == ca || j == cb)) {
				cout << '*';
			}
			else cout << '.';
		}
		cout << endl;
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) solve();
}
