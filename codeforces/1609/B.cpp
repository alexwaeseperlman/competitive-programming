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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q; cin >> n >> q;
	string s; cin >> s;

	int total = 0;
	for (int i = 2; i < s.size(); i++) {
		if (s[i] == 'c' && s[i-1] == 'b' && s[i-2] == 'a') {
			total++;
		}
	}

	while (q--) {
		int i;
		char c; cin >> i >> c;
		i--;

		for (int j = max(i-3, 0); j <= min(i+3, n-3); j++) {
			bool oldAbc = true, newAbc = true;
			for (int k = j; k < j+3; k++) {
				oldAbc = oldAbc && s[k] == ('a'+k-j);
				char old = s[i];
				s[i] = c;
				newAbc = newAbc && s[k] == ('a'+k-j);
				s[i] = old;
			}
			//cout << oldAbc << " " << newAbc << endl;
			if (oldAbc && !newAbc) total--;
			if (newAbc && !oldAbc) total++;
		}
		s[i] = c;

		cout << total << endl;
		
	}

}
