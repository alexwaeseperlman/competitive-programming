#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

int main() {
	ll n, m, w;
	cin >> n >> m >> w;
	priority_queue<pair<ll, pair<ll, ll>>> visits;

	vector<vector<ll>> world = vector<vector<ll>>(n, vector<ll>(m, 0));
	vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));
	set<pair<ll, ll>> portals;

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			ll v; cin >> v;
			if (v > 0) portals.emplace(i, j);

			world[i][j] = v;
		}
	}

	bool portalsVisited = false;


	/*
	for (int i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j < m; j++) {
			cout << world[i][j] << " ";
		}
	}
	cout << endl;
	*/

	visits.emplace(0, make_pair(0, 0));

	ll cost = -1;
	while (visits.size()) {
		cout << visits.size() << endl;
		auto top = visits.top();
		visits.pop();

		ll i = top.second.first, j = top.second.second;
		//cout << i << ", " << j << endl;
		if (i == n - 1 && j == m - 1) {
			cost = -top.first;
			break;
		}

		if (visited[i][j]) continue;
		visited[i][j] = true;
		portals.erase({i, j});

		if (i > 0 && world[i-1][j] != -1) visits.emplace(top.first - w, make_pair(i-1, j));
		if (j > 0 && world[i][j-1] != -1) visits.emplace(top.first - w, make_pair(i, j-1));
		if (i < n-1 && world[i+1][j] != -1) visits.emplace(top.first - w, make_pair(i+1, j));
		if (j < m-1 && world[i][j+1] != -1) visits.emplace(top.first - w, make_pair(i, j+1));

		if (world[i][j] > 0) {
			portalsVisited = true;
			for (auto portal : portals) {
				ll k = portal.first, l = portal.second;
				if (!visited[k][l]) {
					visits.emplace(top.first - world[i][j] - world[k][l], make_pair(k, l));
					visited[k][l] = true;
				}
			}
		}
	}

	cout << cost << endl;
	return 0;
}
