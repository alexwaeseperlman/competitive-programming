#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll c, d, b, m;

ll sum(ll n) {
	ll total = 0;
	while (n) {
		total += n%b;
		n/=b;
	}
	return total;
}

int main() {
	cin >> c >> d >> b >> m;

	ll a = d;
	for (ll i = 0; i < 100; i++) {
		a += c;
		cout << a << ": " << sum(a) << ", ";
	}
	cout << endl;

}
