#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bitset<1000001> add;
vector<ll> o[2];
int main() {
	ll n; cin >> n;
	ll target = (n*n+n)/2;
	if (target&1) {
		cout << "NO" << endl;
		return 0;
	}

	ll total = 0;
	for (int i = n; i >= 0; i--) {
		total += i;
		add[i] = true;
		if (total > target/2) {
			add[i] = false;
			total -= i;
			add[(target/2)-total] = true;
			break;
		}
	}
	for (ll i = 1; i <= n; i++) {
		o[add[i]].push_back(i);
	}

	cout << "YES" << endl;
	for (ll i : {0, 1}) {
		cout << o[i].size() << endl;
		for (ll j : o[i]) cout << j << " ";
		cout << endl;
	}

}
