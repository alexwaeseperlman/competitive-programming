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

ordered_set<int> cycles[100001];
int perm[100001], idxs[100001], cycle[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q; cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> perm[i];
		idxs[perm[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		if (cycle[i]) continue;
		int j = i;
		do {
			cycle[j] = i;
			cycles[i].insert(j);
			j = perm[j];
		} while (j != i);
	}

}
