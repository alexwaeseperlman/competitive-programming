#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	int ok = k;
	for (int i = 0; i < k; i++) {
		if (i+1 < 2*k - n) cout << i+1 << " ";
		else cout << ok-- << " ";
	}
	cout << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();

}
