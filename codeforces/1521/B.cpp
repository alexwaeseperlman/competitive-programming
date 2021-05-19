#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
 
struct Node {
	vector<Node*> children;
	vector<Node*> parents;
	ll id = 0;
};

template<typename T>
ull vecMinIdx(vector<T> a) {
	ull minIdx = 0;
	for (ll i = 0; i < a.size(); i++) {
		if (a[i] < a[minIdx]) minIdx = i;
	}
	return minIdx;
}
 
Node *lca(Node *l, Node *r) {
	if (l->parents.size() > r->parents.size()) return lca(r, l);
 
	ll lb = 0, ub = l->parents.size();
 
	while (ub - lb > 1) {
		ll i = (lb + ub) / 2;
 
		if (l->parents[i] == r->parents[i]) lb = i;
		else ub = i;
	}
 
	return l->parents[lb];
}
 
vector<Node> nodes;
 
Node *buildTree(ll n, vector<pair<ll, ll>> &edges) {
	vector<vector<ll>> edge_list;
	edge_list.resize(n+1);
 
	for (auto edge : edges) {
		edge_list[edge.first].push_back(edge.second);
		edge_list[edge.second].push_back(edge.first);
	}
 
	nodes.resize(n+1);
	Node *root = &nodes[1];
	root->parents.push_back(root);
	root->id = 1;
	
	stack<Node*> dfs;
	dfs.push(root);
 
	for (ull i = 0; i < nodes.size(); i++) nodes[i].id = i;
 
	while (dfs.size()) {
		Node *c = dfs.top();
		dfs.pop();
 
		for (ll i : edge_list[c->id]) {
			if (nodes[i].children.size() == 0) {
				c->children.push_back(&nodes[i]);
			}
		}
 
		for (Node *i : c->children) {
			i->parents = c->parents;
			i->parents.push_back(i);
			dfs.push(i);
		}
	}
 
 
	return root;
}
 
vector<Node*> leaves(Node *root) {
	vector<Node*> leaves;
 
	stack<Node*> dfs;
	dfs.push(root);
 
	while (dfs.size()) {
		Node *c = dfs.top();
		dfs.pop();
 
		if (c->children.size() == 0) leaves.push_back(c);
		else for (Node *i : c->children) dfs.push(i);
	}
 
	return leaves;
}

set<ull> primes(ull n) {
	vector<bool> composite(n, false);

	set<ull> p;

	for (ll i = 2; i < n; i++) {
		if (!composite[i]) {
			p.insert(i);
			for (ull j = i * 2; j < n; j += i) {
				composite[j] = true;
			}
		}
	}

	return p;
}

set<ull> prime;
ull pa = 1000000007, pb = 1000000009;

void solve() {
	ull n; cin >> n;
	vector<ull> a(n);
	for (ull i = 0; i < n; i++) cin >> a[i];

	ull minIdx = vecMinIdx(a);

	cout << n - 1 << endl;
	for (ull i = 0; i < n; i++) {
		if (i == minIdx) continue;
		cout << i + 1 << " " << minIdx + 1 << " " << (i % 2 == 0 ? pa : pb) << " " << a[minIdx] << endl;
	}
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}

