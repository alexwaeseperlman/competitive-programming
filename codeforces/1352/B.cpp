#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n, k; cin >> n >> k;
	
	ll even = 0;
	ll odd = 0;
	for (ll i = 0; i < k - 1; i++) {
		even += 2;
		odd++;
	}

	if ((n - even) % 2 == 0 && even <= n - 2) {
		cout << "YES" << endl;
		for (ll i = 0; i < k - 1; i++) cout << "2 ";
		cout << (n - even) << endl;
	}
	else if ((n - odd) % 2 == 1 && odd <= n -1) {
		cout << "YES" << endl;
		for (ll i = 0; i < k - 1; i++) cout << "1 ";
		cout << (n - odd) << endl;
	}
	else cout << "NO" << endl;
}

int main() {
	ll t; cin >> t;
	while (t--) solve();

}
