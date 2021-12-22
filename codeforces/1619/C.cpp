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

void solve() {
	string a, s; cin >> a >> s;
	
	string b = "";
	bool good = true;

	int n = 0, p = 1, j = a.size()-1;
	for (int i = s.size()-1; i >= 0; i--) {
		n += p*(s[i]-'0');
		p *= 10;
		if (n >= (j >= 0 ?a[j]:'0') - '0') {
			char c = n - ((j >= 0?a[j]:'0')-'0') + '0';
			if (c > '9' || c < '0') good = false;
			b += c;
			n = 0;
			p = 1;
			j--;
		}
	}
	reverse(b.begin(), b.end());
	while (b.size() < a.size()) b = "0"+b;
	while (a.size() < b.size()) a = "0"+a;
	string out = "";
	for (int i = a.size()-1; i >= 0; i--) {
		int n = (a[i] - '0') + (b[i] - '0');
		out = to_string(n) + out;
	}
	if (out == s && good) {
		while (b[0] == '0') b = b.substr(1);
		cout << b << endl;
	}
	else cout << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) solve();

}
