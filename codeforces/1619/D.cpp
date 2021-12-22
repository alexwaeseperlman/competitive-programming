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

void solve() {
	ll m, n; cin >> m >> n;
	vector<vector<ll>> stores(m, vector<ll>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) cin >> stores[i][j];
	}
	ll lb = 1, ub = 1000000000;
	
	while (lb < ub) {
		ll mid = (lb+ub+1)/2;
		vector<bool> sat(n);
		bool had = false;
		for (int i = 0; i < m; i++) {
			int count = 0;
			for (int j = 0; j < n; j++) {
				if (stores[i][j] >= mid) {
					sat[j] = true;
					count++;
				}
			}
			if (count >= 2) had = true;
		}
		bool all = true;
		for (bool a : sat) all = all && a;
		if (had && all) lb = mid;
		else ub = mid-1;
	}

	cout << lb << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) solve();

}
