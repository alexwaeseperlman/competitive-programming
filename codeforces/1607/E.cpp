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
	int n, m; cin >> n >> m;
	
	string s; cin >> s;

	int x = 0, y = 0, w = 1, h = 1, ox = 0, oy = 0, mox = 0, moy = 0;

	for (char c : s) {
		if (w == m && h == n) {
			break;
		}
		if (c == 'U') {
			if (oy) oy--;
			else {
				if (h == n) break;
				y++;
			}
		}
		else if (c == 'L') {
			if (ox) ox--;
			else {
				if (w == m) break;
				x++;
			}
		}
		else if (c == 'D') {
			if (h == n && oy == moy) break;
			oy++;
		}
		else if (c == 'R') {
			if (w == m && ox == mox) break;
			ox++;
		}
		mox = max(mox, ox);
		moy = max(moy, oy);
		h = max(h, y+moy);
		w = max(w, x+mox);
	}
	cout << y+1 << " " << x+1 << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) solve();

}
