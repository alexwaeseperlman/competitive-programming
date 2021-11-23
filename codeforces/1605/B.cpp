#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;

	string s; cin >> s;
	int ones = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') ones++;
	}

	vector<int> ops;
	int l = 0, r = n-1;
	while (l < r) {
		while (s[l] != '1') {
			l++;
		}
		while (s[r] != '0') {
			r--;
		}

		if (l < r) {
			ops.push_back(l+1);
			ops.push_back(r+1);
		}
		l++;
		r--;
	}
	sort(ops.begin(), ops.end());
	if (ops.size()) {
		cout << 1 << endl;
		cout << ops.size() << " ";
		for (int i : ops) cout << i << " ";
		cout << endl;
	}
	else cout << 0 << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();

}
