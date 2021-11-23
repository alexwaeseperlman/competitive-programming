#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int main() {
	ll n; cin >> n;
	vector<pair<ll, pair<ll, ll>>> edges;
	for (ll i = 0; i < n-1; i++) {
		ll a, b, c; cin >> a >> b >> c;
		edges.emplace_back(c, pair<ll, ll>{a, b});
	}
	vector<map<ll, ll>> paths(n+1, map<ll, ll>{ {0, 0} });
	sort(edges.begin(), edges.end());

	for (auto edge : edges) {
		ll l = prev(paths[edge.second.first].lower_bound(edge.first))->second,
		   r = prev(paths[edge.second.second].lower_bound(edge.first))->second;

		if (paths[edge.second.first][edge.first]) paths[edge.second.first][edge.first] += r+1;
		else paths[edge.second.first][edge.first] = r + l+1;
		if (paths[edge.second.second][edge.first]) paths[edge.second.second][edge.first] += l+1;
		else paths[edge.second.second][edge.first] = r+l+1;
	}

	ll total = 0;
	for (auto i : paths) {

		total += i.rbegin()->second;
	}
	cout << total << endl;
}
