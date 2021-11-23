#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll n, val, moves = 0; cin >> n;
	cin >> val;
	for (int i = 1; i < n; i++) {
		ll x; cin >> x;
		moves += max(0ll, val - x);
		val = max(val, x);
	}
	cout << moves << endl;
}
