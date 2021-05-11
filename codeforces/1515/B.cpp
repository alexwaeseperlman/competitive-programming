#include <iostream>

using namespace std;
using ll = long long;

ll isqrt(ll n) {
	if (n == 1) return 1;
	ll lb = 0, ub = n;
	while (ub - lb > 1) {
		ll s = (lb + ub) / 2;
		if (s * s == n) return s;
		else if (n > s * s) lb = s;
		else if (n < s * s) ub = s;
	}
	return lb;
}

bool psquare(ll n) {
	ll s = isqrt(n);
	return s * s == n;
}


int main() {
	ll t, n;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		cin >> n;
		if ((n % 2 == 0  && psquare(n / 2)) || (n % 4 == 0 && psquare(n / 4))) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
