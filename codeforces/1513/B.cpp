#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using ll = long long;

void solve() {
	ull n; cin >> n;
	vector<ull> a(n);

	for (ull i = 0; i < n; i++) cin >> a[i];

	ull m = *min_element(a.begin(), a.end());

	ull count = 0ull;
	for (ull i = 0ull; i < n; i++) count += a[i] == m;

	ull out = count * (count - 1ull);

	ull t = m;
	for (ull k : a) t &= k;
	if (t != m) out = 0ull;

	for (ull i = 1ull; i <= n - 2ull; i++) {
		out = (out * i) % 1000000007ull;
	}

	cout << out << endl;
}

int main() {
	ull t; cin >> t;
	while (t--) solve();
}
