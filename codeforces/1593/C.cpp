#include <bits/stdc++.h>
using namespace std;
using ull = long long;

void solve() {
	ull n, k; cin >> n >> k;

	vector<ull> mice(k);
	for (int i = 0; i < k; i++) {
		cin >> mice[i];
		mice[i] = n - mice[i];
	}
	sort(mice.begin(), mice.end());

	ull sum = 0, count = 0;
	for (ull i = 0; i < k; i++) {
		sum += mice[i];
		if (n - sum <= 0) break;
		count++;
	}

	cout << count << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;

	while (t--) solve();
}
