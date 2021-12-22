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

int dsu[2001];
int dsuSize[2001];
set<int> p;

int parent(int i) {
	if (dsu[i] == i) return i;
	dsu[i] = parent(dsu[i]);
	return dsu[i];
}

int getSize(int i) {
	return dsuSize[parent(i)];
}

bool join(int i, int j) {
	if (parent(i) == parent(j)) return false;
	p.erase(parent(i));
	dsuSize[parent(j)] += getSize(i);
	dsu[parent(i)] = parent(j);
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i <= 2000; i++) dsuSize[i] = 1;
	for (int i = 0; i <= 2000; i++) {
		dsu[i] = i;
	}

	int n, d; cin >> n >> d;
	for (int i = 1; i <= n; i++) p.insert(i);
	int unused = 0;
	while (d--) {
		int x, y; cin >> x >> y;
		if (!join(x, y)) {
			unused++;
		}

		vector<int> sizes;
		for (int i : p) {
			sizes.push_back(getSize(i));
		}
		sort(sizes.begin(), sizes.end());
		reverse(sizes.begin(), sizes.end());
		int total = 0;
		for (int i = 0; i < unused+1; i++) {
			total += sizes[i];
		}
		cout << total-1 << endl;
	}
}
