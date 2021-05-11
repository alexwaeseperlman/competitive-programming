#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ll n, t;
	cin >> n >> t;

	ll prefixSum[n + 1];

	for (ll i = 1; i <= n; i++) {
		ll a; cin >> a;
		prefixSum[i] = prefixSum[i - 1] + a;
	}

	ll maxRead = 0;
	for (ll i = 0; i < n + 1; i++) {
		ll lb = i, ub = n + 1;

		while (ub - lb > 1) {
			ll m = (lb + ub) / 2;
			if (prefixSum[m] - prefixSum[i] <= t) lb = m;
			else if (prefixSum[m] - prefixSum[i] > t) ub = m;
		}

		if (lb - i > maxRead) {
			maxRead = lb - i;
		}
	}
	cout << maxRead << endl;
}
