#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll t; cin >> t;
	while (t--) {
		ll n; cin >> n;

		vector<ll> a;

		for (ll i = 1; i <= n; i *= 10) {
			ll k = (n / i) % 10;
			if (k) a.push_back(k*i);
		}

		cout << a.size() << endl;
		for (ll i : a) cout << i << " ";
		cout << endl;

		cout << endl;
	}
}


