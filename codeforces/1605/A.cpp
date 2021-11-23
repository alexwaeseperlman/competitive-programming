#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll a, b, c; cin >> a >> b >> c;

	ll s = a+b-2*c;
	ll out = ((3+(s)%3)%3);
	cout << (out ? 1 : 0) << endl;
}

int main() {
	int t; cin >>t;
	while (t--) solve();

}

