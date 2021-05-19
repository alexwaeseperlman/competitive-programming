#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n, m; cin >> n >> m;

	vector<multiset<ll>> connections(n);

	multiset<pair<ll, ll>> paths;

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			ll k; cin >> k;
			connections[i].insert(k);
			paths.emplace(k, i);
		}
	}

	vector<pair<ll, ll>> runners(m);

	for (ll i = 0; i < m; i++) {
		runners[i] = *paths.begin();
		paths.erase(paths.begin());
	}

	for (ll j = 0; j < n; j++) {
		for (ll i = 0; i < m; i++) {
			ll largest = *connections[j].rbegin();
			ll chosen = j == runners[i].second ? runners[i].first : largest;

			cout << chosen << " ";

			connections[j].erase(connections[j].lower_bound(chosen));

		}
		cout << endl;
	}
}

int main() {
	ll t; cin >> t;
	while (t--) solve();

}
