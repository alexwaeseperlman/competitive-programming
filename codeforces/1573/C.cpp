#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node {
	unordered_set<Node*> parents;
	unordered_set<Node*> children;
	int id;
	~Node() {
		for (Node *i : children) delete i;
		children.clear();
	}
	Node(int id): id(id) {}
};

void solve() {
	int n; cin >> n;

	vector<Node*> nodes(n+1);

	for (int i = 1; i <= n; i++) {
		if (!nodes[i]) nodes[i] = new Node(i);
		int k; cin >> k;

		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			if (!nodes[a]) nodes[a] = new Node(a);
			nodes[a]->children.insert(nodes[i]);
			nodes[i]->parents.insert(nodes[a]);
		}
	}

	vector<int> dist(n+1, -1);
	vector<bool> visited(n+1);
	
	stack<Node*> dfs;
	for (int i = 1; i <= n; i++) {
		if (nodes[i]->parents.size() == 0) {
			dist[i] = 1;
			dfs.push(nodes[i]);
		}
	}

	while (dfs.size()) {
		Node *top = dfs.top();
		dfs.pop();
		if (visited[top->id]) continue;

		bool notUnderstood = false;
		int m = dist[top->id];
		for (Node *i : top->parents) {
			if (!visited[i->id]) {
				notUnderstood = true;
				break;
			}
			m = max(dist[i->id] + (i->id > top->id), m);
		}
		if (notUnderstood) continue;
		for (Node *i : top->children) {
			if (!visited[i->id]) dfs.push(i);
		}
		visited[top->id] = true;
		dist[top->id] = m;
	}

	int m = 0;
	bool failed = false;
	for (int i = 1; i <= n; i++) {
		m = max(m, dist[i]);
		if (dist[i] == -1) failed = true;
	}
	if (failed) cout << -1 << endl;
	else cout << m << endl;

	for (int i = 1; i <= n; i++) delete nodes[i];
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
