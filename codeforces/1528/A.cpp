#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll n = 200050;

ll l[n], r[n];
pair<ll, ll> dp[n];
vector<ll> adj[n];

void dfs(ll n, ll p) {
	dp[n] = {0, 0};
	
	for (ll i : adj[n]) {
		if (p == i) continue;
		dfs(i, n);
		dp[n].first += max(abs<ll>(l[n] - l[i]) + dp[i].first, abs<ll>(l[n] - r[i]) + dp[i].second);
		dp[n].second += max(abs<ll>(r[n] - l[i]) + dp[i].first, abs<ll>(r[n] - r[i]) + dp[i].second);
	}
}

void solve() {
	ll n; cin >> n;
	for (ll i = 0; i < n; i++) adj[i].clear();

	for (ll i = 0; i < n; i++) cin >> l[i+1] >> r[i+1];
	for (ll i = 0; i < n-1; i++) {
		ll a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, -1);

	cout << max(dp[1].first, dp[1].second) << endl;
}

int main() {
	ll n; cin >> n;
	while (n--) solve();
}
