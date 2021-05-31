#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
 
struct Node {
	vector<Node*> children;
	vector<Node*> parents;
	ull id = 0;
};
 
Node *lca(Node *l, Node *r) {
	if (l->parents.size() > r->parents.size()) return lca(r, l);
 
	ull lb = 0, ub = l->parents.size();
 
	while (ub - lb > 1) {
		ull i = (lb + ub) / 2;
 
		if (l->parents[i] == r->parents[i]) lb = i;
		else ub = i;
	}
 
	return l->parents[lb];
}
 
vector<Node> nodes;
 
Node *buildTree(ull n, vector<pair<ull, ull>> &edges) {
	nodes.clear();
	vector<vector<ull>> edge_list;
	edge_list.resize(n+1);
 
	for (auto edge : edges) {
		edge_list[edge.first].push_back(edge.second);
		edge_list[edge.second].push_back(edge.first);
	}
 
	nodes.resize(n);
	Node *root = &nodes[0];
	root->id = 1;
	
	stack<Node*> dfs;
	dfs.push(root);
 
	for (ull i = 0; i < nodes.size(); i++) nodes[i].id = i;
 
	while (dfs.size()) {
		Node *c = dfs.top();
		dfs.pop();
 
		for (ull i : edge_list[c->id]) {
			if (nodes[i].children.size() == 0) {
				c->children.push_back(&nodes[i]);
			}
		}
 
		for (Node *i : c->children) {
			cout << c->id << " " << i->id << endl;
			i->parents = c->parents;
			i->parents.push_back(c);
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
	vector<bool> composite(n);

	set<ull> p;

	for (ull i = 2; i < n; i++) {
		if (!composite[i]) {
			p.insert(i);
			for (ull j = i * 2; j < n; j += i) {
				composite[j] = true;
			}
		}
	}

	return p;
}

ull mex(ull id, vector<Node*> &parents) {
	vector<ull> path;
	path.reserve(parents.size() + 1);
	path.push_back(id);
	for (Node *n : parents) path.push_back(n->id);

	sort(path.begin(), path.end());
	for (ull i = 0; i < path.size(); i++) {
		if (i != path[i]) {
			return i;
		}
	}
	return path.size();
}

void solve() {
	ull n; cin >> n;
	vector<pair<ull, ull>> edges(n-1);

	for (ull i = 0; i < n - 1; i++) {
		cin >> edges[i].first >> edges[i].second;
	}

	Node *root = buildTree(n, edges);

	vector<ull> mexs(n + 1, 0);

	for (Node node : nodes) {
		ull m = mex(node.id, node.parents);

		ull i = 0;
		while (i < node.parents.size()) {
			cout << "idx " << node.id << " " << node.parents[i]->id << " " << m << endl;
			mexs[m]++;
			if (node.parents[i]->id < m) m = node.parents[i]->id;
			i++;
		}
	}
	for (ull m : mexs) cout << m << " ";
	cout << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}

