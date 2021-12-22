#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll base = 1000000007;

ll modPow(ll n, ll p) {
	ll out = 1, x = n;
	while (p) {
		if (p&1) out = (out*x)%base;
		x = (x*x)%base;
		p >>= 1;
	}
	return out;
}

ll mul(ll a, ll b) {
	return ((a%base)*(b%base))%base;
}
ll add(ll a, ll b) {
	ll x = (a%base)+(b%base);
	if (x > base) x -= base;
	return x;
}

int main() {
	ll n; cin >> n;

	ll sum = 1, count = 1, prod = 1, oc = 1;
	for (int _ = 0; _ < n; _++) {
		ll i, j; cin >> i >> j;
		count = mul(count,(j+1))%base;
		sum = mul(sum, mul(modPow(i, j+1) - 1, modPow(i-1, base-2)));
		ll amt = (j*(j+1)/2)%(base-1);
		prod = mul(modPow(prod, j+1), modPow(i, (amt*oc)%(base-1)));
		oc = (oc*(j+1))%(base-1);
	}
	cout << count << " " << sum << " " << prod<< endl;
}
