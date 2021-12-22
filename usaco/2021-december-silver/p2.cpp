#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dsu[100005];
vector<ll> members[100005];
ll dp[100005];

ll N, M;

void clear() {
	for (ll i = 0; i <= N; i++) {
		dsu[i] = i;
		members[i] = vector<ll>();
		dp[i] = numeric_limits<ll>::max();
	}
}

ll parent(ll i) {
	if (dsu[i] == i) return dsu[i];
	dsu[i] = parent(dsu[i]);
	return dsu[i];
}

void merge(ll i, ll j) {
	dsu[parent(i)] = parent(j);
}

bool connected(ll i, ll j) {
	return parent(i) == parent(j);
}

ll closest(vector<ll> &arr, ll val) {
	ll lb = 0, ub = arr.size();
	while (lb < ub) {
		ll m = (lb+ub)/2;
		if (arr[m] < val) lb = m+1;
		else ub = m;
	}
	ll best = lb;
	for (ll i = max(lb-10, 0ll); i < min(lb+11, (ll)arr.size()); i++) {
		if (abs(val - arr[i]) < abs(val - arr[best])) best = i;
	}
	return arr[best];
}

void solve() {
	cin >> N >> M;
	clear();
	for (ll i = 0; i < M; i++) {
		ll x, y; cin >> x >> y;
		merge(x, y);
	}

	for (ll i = 1; i <= N; i++) {
		members[parent(i)].push_back(i);
	}
	
	for (ll i = 1; i <= N; i++) {
		ll c = closest(members[parent(N)], i);
		dp[parent(i)] = min(dp[parent(i)], (c-i)*(c-i));
	}
	
	ll best = numeric_limits<ll>::max();
	for (ll i = 1; i <= N; i++) {
		ll c = closest(members[parent(1)], i);
		best = min(best, dp[parent(i)] + (c-i)*(c-i));
	}

	cout << best << endl;
}

int main() {
	int T; cin >> T;
	while (T--) solve();
}
