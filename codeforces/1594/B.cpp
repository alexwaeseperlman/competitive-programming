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

const ll base = 1000000007;

template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ull gcd(ull a, ull b) {
	if (b > a) return gcd(a, b);
	if (b == 0) return a;
	return gcd(b, a%b);
}

void solve() {
	ll n, k; cin >> n >> k;
	ll out = 0;

	ll pval = 1;
	for (ll i = 1; i <= k; i <<= 1) {
		out = (out+((pval * ((k & i) > 0))%base))%base;
		pval = (pval*n)%base;
	}

	cout << out << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();

}
