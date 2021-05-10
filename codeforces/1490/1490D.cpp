#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll st[101][10];

void build_table(vector<ll> &data) {
	for (ll i = 0; i < data.size(); i++) {
		st[i][0] = i;
	}

	for (ll i = 1, s = 1; i < 10; i++, s *= 2) {
		for (ll j = 0; j < data.size(); j++) {
			ll n_idx = min(j + s, (ll)data.size());
			st[j][i] = data[st[j][i-1]] > data[st[n_idx][i-1]] ? st[j][i-1] : st[n_idx][i-1];
		}
	}
}

ll query_table(ll start, ll end, vector<ll> &data) {
	ll size = log2(end - start);
	ll offset = 1 << size;

	return data[st[start][size]] > data[st[end - offset][size]] ? st[start][size] : st[end - offset][size];
}

struct tree_node {
	tree_node *l, *r;
	int idx;

	~tree_node() {
		delete l;
		delete r;
	}
};

int depths[101];

tree_node *build_tree(ll l, ll m, ll r, vector<ll> &data, ll depth=0) {
	if (r-l <= 0) return nullptr;
	depths[m] = depth;
	tree_node *root = new tree_node();
	root->idx = m;
	root->l = build_tree(l, query_table(l, m, data), m, data, depth+1);
	root->r = build_tree(m + 1, query_table(m + 1, r, data), r, data, depth+1);
	
	return root;
}

void solve() {
	ll n; cin >> n;
	vector<ll> arr(n);
	for (ll i = 0; i < n; i++) cin >> arr[i];

	build_table(arr);

	vector<ll> out(n);

	delete build_tree(0, query_table(0, n, arr), n, arr);

	for (int i = 0; i < n; i++) cout << depths[i] << " ";
	cout << endl;
}

int main() {
	ll t; cin >> t;
	while (t--) solve();

}
