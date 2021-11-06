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
	
	ll out = 6, prow = 4;
	for (int i = 1; i < k; i++) {
		prow = (prow*prow)%base;
		out *= prow;
		out %= base;
	}

	cout << out << endl;

}
