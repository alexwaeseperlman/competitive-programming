#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n, m; cin >> n >> m;
	vector<ll> a(m);
	for (ll i = 0; i < m; i++) cin >> a[i];
	vector<vector<ll>> c(n+1), p(n+1);
	ll total = 0;
	for (ll i = 0; i < m-1; i++) {
		if (a[i] == a[i+1]) continue;
		total += abs(a[i] - a[i+1]);
		c[a[i]].push_back(a[i+1]);
		c[a[i+1]].push_back(a[i]);
	}

	for (int i = 1; i <= n; i++) {
		c[i].push_back(0);
		sort(c[i].begin(), c[i].end());

		p[i] = vector<ll>(c[i].size());
		for (int j = 1; j < c[i].size(); j++) {
			p[i][j] += p[i][j-1] + c[i][j];
		}
	}


	auto testSwap = [&](ll a, ll b) -> ll {
		ll bidx = lower_bound(c[a].begin(), c[a].end(), b) - c[a].begin();
		bidx--;
		ll aidx = lower_bound(c[a].begin(), c[a].end(), a) - c[a].begin();
		aidx--;
		ll before = a*2*aidx + p[a][c[a].size()-1] - 2*p[a][aidx] - a*(c[a].size()-1);
		ll after = b*2*bidx + p[a][c[a].size()-1] - 2*p[a][bidx] - b*(c[a].size()-1);
		return total - before + after;
	};

	ll best = total;

	for (ll i = 1; i <= n; i++) {
		ll lb = 1, ub = n+1;
		while (lb < ub) {
			ll m = (lb+ub)/2;
			ll slope = testSwap(i, m+1) - testSwap(i, m);
			if (slope <= 0) lb = m+1;
			else ub = m;
		}
		if (testSwap(i, lb) <= best) {
			best = min(best, testSwap(i, lb));
		}
		//for (ll j = 1; j <= n; j++) best = min(best, testSwap(i, j));
	}
	cout << best << endl;
}
