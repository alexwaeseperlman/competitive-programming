#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
 
const ll base = 998244353;

ll factOver(ll n, ll k) {
	ll j = 1;
	ll o = 1;
	for (ll i = k+1; i <= n; i++) {
		o = (o * i) % base;
	}
	return o % base;
}
 
void solve() {
	ll n; cin >> n;
 
	map<ll, ll> counts;
	for (ll i = 0; i < n; i++) {
		ll p; cin >> p;
		counts[p]++;
	}
	ll max = counts.rbegin()->first, smax = next(counts.rbegin())->first;
	if (counts[max] == 1 && max - smax > 1) {
		cout << 0 << endl;
		return;
	}
	if (counts[max] == 1 && smax != max) {
		if (n == 2) {
			cout << 1 << endl;
			return;
		}
		ll c = (factOver(n, counts[smax]+1) * factOver(counts[smax], 1)) % base;
		
		cout << (base + factOver(n, 1) - c) % base << endl;
 
		return;
	}
	// Since there are two with the max, every combination is acceptable
	cout << factOver(n, 1) << endl;
	return;
}
int main() { int t; cin >> t; while (t--) solve(); }
