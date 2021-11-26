#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll t; cin >> t;
	for (ll k = 1; k <= t; k++) {
		if (k == 1) cout << 0 << endl;
		else if (k == 2) cout << 6 << endl;
		else if (k == 3) cout << 28 << endl;
		else {
			ll out = 0;
			out += (k-4)*(k-4) * (k*k-9);
			out += 4*(k-4) * (k*k-7);
			out += 4*(k-4) * (k*k-5);
			out += 4 * (k*k-5);
			out += 4 * (k*k-3);
			out += 8 * (k*k-4);

			cout << out / 2 << endl;
		}

	}

}
