#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n;
	string a, b;
	cin >> a >> b;

	bitset<2> seen;
	int total = 0;
	for (int i = 0; i < n; i++) {
		if (seen[0] && (a[i] == '0' || b[i] == '0')) {
			seen[0] = false;
			total++;
		}
		seen[a[i] - '0'] = true;
		seen[b[i] - '0'] = true;

		if (seen[0] && seen[1]) {
			total += 2;
			seen[0] = false;
			seen[1] = false;
		}
	}
	if (seen[0]) total++;

	cout << total << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();

}
