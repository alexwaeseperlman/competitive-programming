#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using number = array<ull, 20>;

number xorBase(number a, number b, ull base) {
	number out = a;
	for (ull i = 0; i < a.size(); i++) {
		out[i] = (a[i] + b[i]) % base;
	}
	return out;
}

number xorInverse(number a, ull base) {
	number out = a;
	for (ull i = 0; i < out.size(); i++) {
		out[i] = base - out[i];
	}
	return out;
}

number inc(number &a, ull base) {
	a[0]++;
	for (int i = 0; i < a.size()-1; i++) {
		if (a[i] >= base) {
			a[i] = 0;
			a[i+1]++;
		}
		else break;
	}
	
	return a;
}

ull from(number a, ull base) {
	ull out = 0;
	for (int i = a.size()-1; i >= 0; i--) {
		out *= base;
		out += a[i];
	}
	return out;
}

void solve() {
	ull n, k; cin >> n >> k;

	number p, x;
	for (int i = 0; i < p.size(); i++) p[i] = 0;
	x = p;

	for (number i = p; from(i, k) <= n; inc(i, k)) {
		number guess = xorBase(((from(i, k) % 2) == 1 ? xorInverse(i, k) : i), p, k);
		cout << from(guess, k) << endl;
		cout.flush();
		ull r; cin >> r;
		if (r) return;

		p = xorBase(guess, xorInverse(p, k), k);
	}
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
