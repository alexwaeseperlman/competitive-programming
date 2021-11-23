#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(2*n);
	for (int i = 0; i < 2*n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	bool solvable = false;
	vector<pair<int, int>> moves;
	int bestX;
	for (int i = 0; i < 2*n-1; i++) {
		vector<pair<int, int>> m;
		multiset<int> left;
		left.insert(a.begin(), a.end());
		int x = a[2*n-1] + a[i];
		int sx = x;
		while (left.size() && x > *left.rbegin()) {
			int top = *left.rbegin();
			left.erase(left.find(top));
			if (left.count(x-top) == 0) break;
			else {
				left.erase(left.find(x-top));
				m.emplace_back(top, x-top);
				x = max(top, x-top);
			}
		}
		if (left.size() == 0) {
			solvable = true;
			bestX = sx;
			moves = m;
			break;
		}
	}
	
	if (solvable) {
		cout << "YES" << endl;
		cout << bestX << endl;
		for (auto [i, j] : moves) {
			cout << i << " " << j << endl;
		}
		
	}
	else cout << "NO" << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
