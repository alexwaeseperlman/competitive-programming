#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
using ll = long long;
using ull = unsigned long long;

struct Node {
	vector<Node*> children;
	vector<Node*> parents;
	ll id = 0;
};

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

int main() {
	ll n; cin >> n;

	vector<pair<ll, ll>> edges;

	edges.resize(n-1);

	for (ll i = 0; i < n - 1; i++) {
		cin >> edges[i].first >> edges[i].second;
	}

	buildTree(n, edges);

	ll leafCount = leaves(&nodes[1]).size();

	vector<Node*> order;
	for (ll i = 0; i < leafCount; i++) {
		ll k; cin >> k;
		order.push_back(&nodes[k]);
	}
	order.push_back(&nodes[1]);

	Node *ptr = &nodes[1];
	vector<ll> path;

	for (ull i = 0; i < order.size() - 1; i++) {
		bool after = false;
		for (ull j = 0; j < order[i]->parents.size() - 1; j++) {
			if (order[i]->parents[j] == ptr) after = true;

			if (after) path.push_back(order[i]->parents[j]->id);
		}
		ptr = lca(order[i], order[i + 1]);
		for (ll j = order[i]->parents.size() - 1; order[i]->parents[j] != ptr; j--) {
			path.push_back(order[i]->parents[j]->id);
		}
	}

	path.push_back(1);

	if ((ll)path.size() == 2 * n - 1) {
		for (ll i : path) cout << i << " ";
		cout << endl;
	}
	else {
		cout << -1 << endl;
	}
}
