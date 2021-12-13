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
	ll n; cin >> n;
	vector<ll> a(n);
	ll swaps = 0;
	for (ll i = 0; i < n; i++) cin >> a[i];
	vector<ll> b(a);
	sort(b.begin(), b.end());
	vector<ll> idxs(n+1, -1);
	bool same = false;
	for (ll i = 0; i < b.size(); i++) {
		if (idxs[a[i]] != -1) same = true;
		idxs[a[i]] = i;
	}
	if (same) {
		cout << "yes" << endl;
		return;
	}
	for (ll i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			int idx = idxs[b[i]];
			swap(idxs[b[i]], idxs[a[i]]);
			swap(a[i], a[idx]);
			swaps++;
		}
	}
	if (swaps%2 == 0) cout << "yes" << endl;
	else cout << "no" << endl;
 
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	ll t; cin >> t;
	while (t--) solve();
 
}
