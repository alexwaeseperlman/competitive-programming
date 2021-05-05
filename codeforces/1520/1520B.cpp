#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll solve() {
	ll n;
	cin >> n;
	ll total = 0;
	for (ll i = 1; i <= n; i = i * 10 + 1) {
		total += min(n / i, 9ll);
	}

	return total;
}

int main() {
	int t;
	cin >> t;
	while (t--) cout << solve() << endl;
}
