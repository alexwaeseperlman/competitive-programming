#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n;

	vector<int> nums(n);
	int digs = 0, total = 0;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		nums[i] = c - '0';
		if (nums[i] != 0) digs++;
		total += nums[i];
	}
	cout << total + digs - 1 + (nums[n-1] == 0) << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
