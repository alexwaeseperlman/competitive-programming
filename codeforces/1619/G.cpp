//#pragma GCC optimize "trapv" 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using namespace __gnu_pbds;

#define print(x) cout << #x << " " << x << endl;
#define print_array(x) (cout << #x); for (auto i : (x)) cout << " " << i; cout << endl;

template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct {
	ll x, y;
} pos[200001];

ll dsu[200001], timeMin[200001];
ll parent(ll i) {
	if (dsu[i] == i) return i;
	dsu[i] = parent(dsu[i]);
	return dsu[i];
}

void merge(ll i, ll j) {
	timeMin[parent(j)] = min(timeMin[parent(j)], timeMin[parent(i)]);
	dsu[parent(i)] = parent(j);
}

void solve() {
	int n, k; cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> pos[i].x >> pos[i].y;
		dsu[i] = i;
		cin >> timeMin[i];
	}

	vector<pair<pair<ll, ll>, ll>> poss(n);
	for (int i = 0; i < n; i++) {
		poss[i].first.first = pos[i].x;
		poss[i].first.second = pos[i].y;
		poss[i].second = i;
	}

	sort(poss.begin(), poss.end());
	for (int i = 1; i < n; i++) {
		if (poss[i-1].first.first == poss[i].first.first && poss[i].first.second - poss[i-1].first.second <= k) {
			merge(poss[i].second, poss[i-1].second);
		}
	}
	for (int i = 0; i < n; i++) {
		swap(poss[i].first.first, poss[i].first.second);
	}

	sort(poss.begin(), poss.end());
	for (int i = 1; i < n; i++) {
		if (poss[i-1].first.first == poss[i].first.first && poss[i].first.second - poss[i-1].first.second <= k) {
			merge(poss[i].second, poss[i-1].second);
		}
	}

	vector<ll> times;
	for (ll i = 0; i < n; i++) {
		if (parent(i) == i) times.push_back(timeMin[parent(i)]);
	}
	sort(times.begin(), times.end());
	//print_array(times);
	int i = 0, j = times.size()-1;
	ll time = 0;
	while (i < j) {
		while (time >= times[i] && i < j) i++;
		if (j > i) {
			time++;
			j--;
		}
	}
	cout << time << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) solve();

}
