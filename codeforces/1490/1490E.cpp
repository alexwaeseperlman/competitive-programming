#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n; cin >> n;
	vector<pair<ll, ll>> players(n, {0,0});
	for (ll i = 0; i < n; i++) {
		cin >> players[i].first;
		players[i].second = i;
	}
	
	sort(players.begin(), players.end());
	
	vector<ll> prefixSums(n, 0);
	prefixSums[0] = players[0].first;
	for (ll i = 1; i < players.size(); i++) {
		prefixSums[i] = prefixSums[i - 1] + players[i].first;
	}
	
	set<ll> included;
	included.insert(players[players.size()-1].second);
	for (ll i = players.size() - 2; i >= 0; i--) {
		if (prefixSums[i] >= players[i + 1].first) included.insert(players[i].second);
		else break;
	}
	
	cout << included.size() << endl;
	for (ll i : included) {
		cout << i + 1 << " ";
	}
	cout << endl;

}

int main() {
	ll t; cin >> t;

	while (t--) solve();

}
