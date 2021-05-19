#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
 
struct Node {
	list<Node*> children;
	ll id = 0;
};
 
vector<Node> nodes;
 
Node *buildTree(ull n, vector<pair<ull, ull>> &edges) {
	nodes.clear();
	vector<vector<ull>> edge_list;

	edge_list.resize(n+1);
 
	for (auto edge : edges) {
		edge_list[edge.first].push_back(edge.second);
		edge_list[edge.second].push_back(edge.first);
	}
 
	nodes.resize(n+1);
	Node *root = &nodes[1];
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
				dfs.push(&nodes[i]);
			}
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

struct search_el {
	Node *node, *parent;
	search_el(Node *node, Node *parent): node(node), parent(parent) {};
};

void solve() {
	ull n; cin >> n;

	// Build a tree based on the undirected edges
	vector<pair<ull, ull>> edges(n-1);
	for (ull i = 0; i < n-1; i++) cin >> edges[i].first >> edges[i].second;
	Node *tree = buildTree(n, edges);

	// Store the order of moves
	vector<tuple<ull, ull, ull, ull>> moves;

	stack<search_el> dfs;
	queue<search_el> backup;
	queue<search_el> loose;
	
	// Push all the children of the root into a search. We can ensure that the root has the right number of edges later
	dfs.emplace(tree->children.front(), tree);
	if (tree->children.size() > 1) dfs.emplace(*next(tree->children.begin()), tree);

	while (tree->children.size() > 2) {
		loose.emplace(tree->children.back(), tree);
		tree->children.erase(prev(tree->children.end()));
	}

	while (dfs.size()) {
		search_el top = dfs.top();
		dfs.pop();

		if (top.node->children.size() > 0) {
			// Push all but the first child of the current node into loose.
			// They must be disconnected and will be put into the first leaf node available
			for (auto i = next(top.node->children.begin()); i != top.node->children.end();) {
				loose.emplace(*i, top.node);
				top.node->children.erase(i++);
			}

			dfs.emplace(*top.node->children.begin(), top.node);
		}
		// If this node has no children we can move something here
		else {
			// If there are no loose nodes back this one up so we can come back to it
			if (loose.size() == 0) {
				backup.push(top);
				continue;
			}
			else {
				while (backup.size()) {
					dfs.push(backup.back());
					backup.pop();
				}
			}
			search_el sub = loose.back();
			loose.pop();
			moves.emplace_back(sub.node->id, sub.parent->id, sub.node->id, top.node->id);
			top.node->children.push_back(sub.node);

			dfs.emplace(sub.node, top.node);
		}
	}

	cout << moves.size() << endl;
	for (ull i = 0; i < moves.size(); i++) {
		cout << get<0>(moves[i]) << " " << get<1>(moves[i]) << " " << get<2>(moves[i]) << " " << get<3>(moves[i]) << endl;
	}
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}

