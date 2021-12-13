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

ull gcd(ull a, ull b) {
	if (b > a) return gcd(a, b);
	if (b == 0) return a;
	return gcd(b, a%b);
}

void solve() {
	ll n, k; cin >> n >> k;
	vector<ll> after, before;
	for (ll i = 0; i < n; i++){
		ll x; cin >> x;
		if (x > 0) after.push_back(x);
		else before.push_back(-x);
	}
	sort(after.begin(), after.end());
	sort(before.begin(), before.end());
	if (after.size() == 0) swap(after, before);

	if (before.size()) {
		if (before.back() > after.back()) swap(before, after);
	}

	ll d = 0;
	d = after.back();
	for (int i = 0; after.size() && i < k; i++) {
		after.pop_back();
	}

	while (after.size()) {
		d += after.back()*2;
		for (int i = 0; after.size() && i < k; i++) after.pop_back();
	}
	while (before.size()) {
		d += before.back()*2;
		for (int i = 0; before.size() && i < k; i++) before.pop_back();
	}

	cout << d << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll t; cin >> t;
	while (t--) solve();

}
