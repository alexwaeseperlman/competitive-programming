#include <bits/stdc++.h>
using namespace std;

int main() {
	int q; cin >> q;
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (q == 2) reverse(a.begin(), a.end());

	int total = 0;
	for (int i = 0; i < n; i++) {
		total += max(a[i], b[i]);
	}
	cout << total << endl;
}
