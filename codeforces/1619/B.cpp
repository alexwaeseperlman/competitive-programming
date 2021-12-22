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


vector<ll> order;
set<ll> seen;
void solve() {
	ll n; cin >> n;

	cout << upper_bound(order.begin(), order.end(), n) - order.begin() << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (ll i = 2; i*i <= 1000000000; i++) {
		order.push_back(i*i);
		seen.insert(i*i);
	}
	for (ll i = 1; i*i*i <= 1000000000; i++) {
		if (seen.count(i*i*i) == 0) order.push_back(i*i*i);
	}

	sort(order.begin(), order.end());

	int t; cin >> t;
	while (t--) solve();
}
