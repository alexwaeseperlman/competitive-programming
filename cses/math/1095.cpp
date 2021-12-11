#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll base = 1000000007;

const ll pow(ll n, ll p, ll base) {
	ll out = 1, x = n;
	for (ll i = 1; i <= p; i <<= 1) {
		if (i&p) out = (out*x)%base;
		x = (x*x)%base;
	}

	return out;
}

int main() {
	int n; cin >> n;

	ll a, b;
	while (n--) {
		cin >> a >> b;
		cout << pow(a, b, base) << endl;
	}

}
