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

struct node {
	int color = -1;
};

ll rsquare(ll b, ll row) {
	ll out = b;
	for (int i = 0; i < row; i++) {
		out = (out*out)%base;
	}
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	int k; cin >> k;
 
	map<string, int> colors;
	colors["white"] = 0;
	colors["yellow"] = 3;
	colors["green"] = 1;
	colors["blue"] = 4;
	colors["red"] = 2;
	colors["orange"] = 5;
	int n; cin >> n;
 	vector<map<ll, node>> rows(63);
	for (int i = 0; i < n; i++) {
		ll v; string s; cin >> v >> s;

		rows[(int)log2(v)][v-(1<<((int)log2(v)))].color = colors[s];
	}

	ll inv=250000002;
	function<ll(ll, ll, int)> subtreeSize = [&](ll row, ll key, int color) -> ll {
		ll out = (((rsquare(4, k-row+1)*inv)%base)*inv)%base;
		
	};
}
