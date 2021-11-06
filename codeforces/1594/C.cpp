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
	int n; char c; cin >> n >> c;
	string s; cin >> s;

	bool all = true;
	for (int i = 0; i < s.size(); i++) {
		all = all && s[i] == c;
	}
	if (all) {
		cout << 0 << endl;
		return;
	}

	for (int i = s.size(); i >= 1; i--) {
		if (2*i <= s.size()) break;
		if (s[i-1] == c) {
			cout << 1 << endl;
			cout << i << endl;
			return;
		}
	}

	cout << 2 << endl;
	cout << s.size() << " " << s.size()-1 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) solve();

}
