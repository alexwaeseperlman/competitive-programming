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
 
const ll base = 1000000007;
 
ull gcd(ull a, ull b) {
	if (b > a) return gcd(a, b);
	if (b == 0) return a;
	return gcd(b, a%b);
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	int k; cin >> k;
 
	map<string, int> colors;
	colors["white"] = 1;
	colors["yellow"] = 4;
	colors["green"] = 2;
	colors["blue"] = 5;
	colors["red"] = 3;
	colors["orange"] = 6;
 
	vector<map<int, set<int>>> open(64);
	vector<map<int, int>> unset(64);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		ll v; string s; cin >> v >> s;
 
		int row = log2(v);
		v -= 1<<row;
		if (open[row].count(v) && !open[row][v].count(colors[s])) {
			cout << 0 << endl;
			return 0;
		}
		else {
			open[row][v] = set<int>{colors[s]};
		}
		if (row > 0 && open[row-1].count(v/2) == 0) {
			open[row-1][v/2] = set<int>{1, 2, 3, 4, 5, 6};
			unset[row-1][v/2] = 2;
		}
		if (row > 0) unset[row-1][v/2]--;
		if (!open[row+1].count(v*2)) open[row+1][v*2] = set<int>{1, 2, 3, 4, 5, 6};
		if (!open[row+1].count(v*2+1)) open[row+1][v*2+1] = set<int>{1, 2, 3, 4, 5, 6};
		for (auto i : { &open[row+1][v*2], &open[row+1][v*2+1] }) {
			i->erase(colors[s]);
			i->erase(1+(colors[s]+2)%6);
		}
		if (row > 0) {
			open[row-1][v/2].erase(colors[s]);
			open[row-1][v/2].erase(1+(colors[s]+2)%6);
		}
	}
	
	ll out = 1, prow = 4, inv = 250000002;
	if (open[0].count(0)) {
		out *= open[0][0].size();
	}
	else out *= 6;
 
	for (int i = 1; i < k; i++) {
		prow = (prow*prow)%base;
		out *= prow;
		out %= base;
		for (auto [idx, s] : open[i]) {
			out = (out*inv)%base;
			if (s.size() == 1) continue;
			out = (out*(s.size()))%base;
		}
	}
 
	cout << out << endl;
}
