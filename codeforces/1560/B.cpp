#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

void solve() {
	ull a, b, c; cin >> a >> b >> c;

	ull l = min(a-1, b-1), h = max(a-1, b-1);

	ull diff = h - l;
	ull size = diff * 2;
	if (c > size || size <= 2 || l >= diff) cout << -1 << endl;
	else {
		cout << (((c-1) + diff) % size) + 1 << endl;
	}
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
