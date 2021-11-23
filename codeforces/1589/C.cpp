#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	bool possible = true;
	for (int i = 0; i < n; i++) {
		if (b[i] - a[i] != 1 && b[i] - a[i] != 0) possible = false;
	}

	if (possible) cout << "YES" << endl;
	else cout << "NO" << endl;


}

int main() {
	int t; cin >> t;
	while (t--) solve();

}
