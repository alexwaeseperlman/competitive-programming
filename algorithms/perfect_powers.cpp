#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;
using ll = mpz_class; 

const ll N("1000000000");

ll ipow(ll n, ll p) {
	if (p == 0) return 1;
	ll e = 1, x = n;
	while (2*e <= p) {
		e *= 2;
		x *= x;
	}
	return x * ipow(n, p-e);
}

struct power {
	ll val, base, exp;
	power(ll val, ll base, ll exp): val(val), base(base), exp(exp) {}
	bool operator<(const power &rh) const {
		return val > rh.val;
	}
};

int main() {
	priority_queue<power> powers;
	for (ll i = 2; i < 1000; i++) {
		powers.emplace(1, 1, i);
	}

	mpf_class sum = 0.0;

	while (powers.top().val < N) {
		power top = powers.top();
		do {
			top = powers.top();
			powers.pop();
			powers.emplace(ipow(top.base+1, top.exp), top.base+1, top.exp);
		} while (powers.top().val == top.val);

		if (top.val == 1) continue;
		sum += mpf_class(1.0) / mpf_class(top.val-1);
		cout << top.base << "^" << top.exp << "=" << top.val << " " << sum << endl;
	}
	cout << sum << endl;
}
