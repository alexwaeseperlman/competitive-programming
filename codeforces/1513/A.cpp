#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

void solve() {
	ull n, k; cin >> n >> k;

	ull max = n;
	ull min = 1;

	vector<ull> out;

	ull peaks = 0;

	while (out.size() < n) {
		out.push_back(min++);
		if (peaks < k) {
			out.push_back(max--);
			peaks++;
			if (max < min - 1) {
				cout << -1 << endl;
				return;
			}
		}
	}

	peaks = 0;
	for (ull i = 1; i < n-1; i++) {
		if (out[i] > out[i-1] && out[i] > out[i+1]) peaks++;
	}
	if (peaks < k) {
		cout << -1 << endl;
		return;
	}
	for (ull i = 0; i < n; i++) cout << out[i] << " ";
	cout << endl;

}

int main() {
	ull t;
	cin >> t;
	while (t--) solve();
}
