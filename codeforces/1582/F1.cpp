#pragma GCC optimize ("O3")
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct state {
	ll max, x;
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n; cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	set<ll> dp;
	vector<ll> ndp;
	vector<ll> xorMax(8192, numeric_limits<ll>::max());
	xorMax[0] = 0;
	dp.insert(0);


	for (ll i : a) {
		if (xorMax[i] == numeric_limits<ll>::max()) ndp.push_back(i);
		xorMax[i] = min(i, xorMax[i]);
		for (ll x : dp) {
			if (i > xorMax[x]) {
				if (xorMax[x^i] == numeric_limits<ll>::max()){
					ndp.push_back(x^i);
				}
				xorMax[x^i] = min(i, xorMax[x^i]);
			}
		}
		dp.insert(ndp.begin(), ndp.end());
		ndp.clear();
	}

	cout << dp.size() << endl;
	for (ll i : dp) cout << i << " ";
	cout << endl;






}
