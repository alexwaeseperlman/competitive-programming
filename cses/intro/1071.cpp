#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pos(ll x, ll y) {
	ll row = max(x, y);
	ll pos;
	if (x == y) return x*x-x+1;
	else if (x == row) {
		pos = 2*row-y;
	}
	else {
		pos = x;
	}


	return (~row&1 ? pos:2*row-pos) + (row-1)*(row-1);
}

int main() {

	ll t; cin >> t;
	while (t--) {
		ll x, y; cin >> x >> y;
		cout << pos(x, y) << endl;
	}

}
