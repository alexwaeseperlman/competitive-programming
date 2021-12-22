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
	ll n; cin >> n;
	vector<ll> a(n), freq(n+1);
	for (ll i = 0; i < n; i++) cin >> a[i];

	for (ll i = 0; i < n; i++) {
		freq[a[i]]++;
	}


	bool possible = true;
	long long cost = 0;
	priority_queue<ll> extra;
	for (ll i = 0; i <= n; i++) {
		if (possible == false) {
			cout << -1 << " ";
		}
		else {
			cout << cost+freq[i] << " ";
			while (freq[i] > 1) {
				freq[i]--;
				extra.push(i);
			}
		}
		if (freq[i] == 0) {
			if (extra.size() == 0) possible = false;
			else {
				cost += i-extra.top();
				freq[i]++;
				extra.pop();
			}
		}
	}
	cout << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll t; cin >> t;

	while (t--) solve();
}
