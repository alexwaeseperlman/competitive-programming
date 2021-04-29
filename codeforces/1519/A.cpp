#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

void solve() {
	ll r, b, diff;
	cin >> r >> b >> diff;

	ll small = min(r, b), large = max(r, b);

	ll max = small * (diff + 1);

	if (large <= max) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) solve();
}
