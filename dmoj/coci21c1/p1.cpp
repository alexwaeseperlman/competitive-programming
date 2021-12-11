#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;

	vector<vector<int>> sprays(8);
	for (int i = 0; i < n; i++) {
		int t, a, b; cin >> t >> a >> b;
		sprays[a-1].push_back(t);
	}
	for (int i = 0; i < 8; i++) sort(sprays[i].begin(), sprays[i].end());

	vector<int> points(2);
	for (int i = 0; i < 8; i++) {
		int chain = 0, p = -1;
		for (int j = 0; j < sprays[i].size(); j++) {
			if (p != -1 && sprays[i][j] - p <= 10) {
				chain = 50;
			}
			else {
				chain = 0;
			}
			points[i/4] += 100 + chain;
			p = sprays[i][j];
		}
	}

	cout << points[0] << " " << points[1] << endl;
}
