#include <bits/stdc++.h>
using namespace std;
using ull = __uint128_t;

ull modPow(ull n, ull p, ull base) {
	if (p == 0) return 1;
	ull e = 1, out = n;

	while (2ull*e <= p) {
		e *= 2;
		out = (out*out)%base;
	}

	return (out*modPow(n, p-e, base))%base;
}


int main() {
	cout << (unsigned long long)((modPow(2ull, 7830457ull, 10000000000ull) * 28433 + 1) % (ull)(10000000000ull))<< endl;
}
