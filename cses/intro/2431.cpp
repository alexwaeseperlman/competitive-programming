#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll k; cin >> k;
	k--;
	ll i = 0, l = 1, c = 9;
	while (i + c*l < k) {
		i += c*l;
		l++;
		c*=10;
	}

	k-=i;
	ll n = k/l+(c/9), d = (k%l);
	cout << to_string(n)[d] << endl;
}

int main() {
	int q; cin >> q;
	while (q--) solve();
}
