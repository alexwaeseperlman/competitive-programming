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
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ull gcd(ull a, ull b) {
	if (b > a) return gcd(a, b);
	if (b == 0) return a;
	return gcd(b, a%b);
}

ordered_set<int> pos[3];

int count() {
	int total = numeric_limits<int>::max();

	//cout << "a: "; for (int i : pos[0]) cout << i << " ";
	//cout << endl;
	//cout << "b: "; for (int i : pos[1]) cout << i << " ";
	//cout << endl;
	//cout << "c: "; for (int i : pos[2]) cout << i << " ";
	//cout << endl;

	total = min(total, (int)pos[0].order_of_key(*pos[2].rbegin()));
	total = min(total, (int)pos[1].order_of_key(*pos[2].rbegin()));
	total = min(total, (int)pos[0].order_of_key(*pos[1].rbegin()));
	
	total = min(total, max((int)(pos[1].order_of_key(*pos[2].rbegin()) - pos[1].order_of_key(*pos[0].begin())), 0));

	total = min(total, (int)pos[0].size());
	total = min(total, (int)pos[1].size());
	total = min(total, (int)pos[2].size());
	return max(total, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q; cin >> n >> q;
	string s; cin >> s;


	for (int i = 0; i < n; i++) {
		pos[s[i]-'a'].insert(i);
	}

	while (q--) {
		int i;
		char c;
		cin >> i >> c;
		i--;

		pos[s[i]-'a'].erase(i);
		pos[c-'a'].insert(i);
		s[i] = c;

		cout << count() << endl;
	}
}
