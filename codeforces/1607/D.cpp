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
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<bool> c(n);
	for (int i = 0; i < n; i++) {
		char x; cin >> x;
		c[i] = x == 'R';
	}

	vector<ll> l, r;
	for (int i = 0; i < n; i++) {
		if (c[i]) r.push_back(a[i]);
		else l.push_back(a[i]);
	}

	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	reverse(r.begin(), r.end());

	int lside = 0, rside = n+1, inc = 0;

	for (ll i : l) if (i > lside) {
		lside++;
		inc++;
	}
	for (ll i : r) if (i < rside) {
		rside--;
		inc++;
	}
	if (inc == n) cout << "yes" << endl;
	else cout << "no" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) solve();

}
