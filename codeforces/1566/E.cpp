#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
	unordered_set<Node*> connections;
	Node* parent;
	int id;
	Node(int _id): id(_id) {};
};

void solve() {
	int n; cin >> n;

	map<int, Node*> nodes;

	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;

		if (!nodes[u]) nodes[u] = new Node(u);
		if (!nodes[v]) nodes[v] = new Node(v);

		nodes[u]->connections.insert(nodes[v]);
		nodes[v]->connections.insert(nodes[u]);
	}

	stack<Node*> dfs;
	dfs.push(nodes[1]);

	while (dfs.size()) {
		Node *top = dfs.top();
		dfs.pop();
		for (Node *c : top->connections) {
			c->connections.erase(top);
			c->parent = top;
			dfs.push(c);
		}
	}

	int budLeafs = 0;
	int budsWithSiblings = 0;
	dfs.push(nodes[1]);
	while (dfs.size()) {
		Node *top = dfs.top();
		dfs.pop();

		if (top->connections.size() > 0) {
			bool bud = true;
			for (Node *c : top->connections) {
				bud = bud && c->connections.size() == 0;
				dfs.push(c);
			}

			if (bud && top->id != 1) {
				dfs.push(top->parent);
				top->parent->connections.erase(top);
			}
		}
	}

	int leafs = 0;

	dfs.push(nodes[1]);

	
	while (dfs.size()) {
		Node *top = dfs.top();
		dfs.pop();
		if (top->connections.size() == 0) leafs++;

		for (Node *c : top->connections) {
			dfs.push(c);
		}
	}


	cout << leafs << endl;


	for (auto p : nodes) {
		delete p.second;
	}
}

int main() {
	int t; cin >> t;

	while (t--) solve();
}
