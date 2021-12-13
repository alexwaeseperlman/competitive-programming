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
	int timeSince = 0;
	int n; cin >> n;
	bool died = false;
	int height = 1;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a == 0) {
			timeSince++;
		}
		else {
			if (timeSince == 0 && i > 0) {
				height += 5;
			}
			else height++;
			timeSince = 0;
		}
		if (timeSince >= 2) {
			died = true;
		}
	}
	if (died) cout << -1 << endl;
	else cout << height << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) solve();

}
