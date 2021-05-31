#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

struct Node {
	ull n;
	Node(ull n): n(n) {};
	shared_ptr<Node> parent; 

	unordered_set<shared_ptr<Node>> children;
};

void solve() {
	ull n; cin >> n;

	vector<ull> a(n+1), b(n+1);
	for (ull arr : {0, 1}) {
		for (ull i = 2; i <= n; i++) {
			cin >> (arr == 0 ? a : b)[i];
		}
	}

	vector<shared_ptr<Node>> nodes(n+1);

	for (ull i = 1; i <= n; i++) {
		nodes[i] = make_shared<Node>(i);
	}
	for (ull i = 2; i <= n; i++) {
		nodes[a[i]]->children.insert(nodes[i]);
		nodes[i]->parent = nodes[a[i]];
	}

	vector<vector<ull>> bc(n+1);
	for (ull i = 2; i <= n; i++) {
		bc[b[i]].push_back(i);
	}

	function<bool(ull n, ull k)> ancestor = [&](ull n, ull k) -> bool {
		cout << "checking ancestry of " << n << " -> " << k << endl;
		while (k != 0) {
			if (k == n) return true;
			k = b[k];
			cout << k << endl;
		}
		return false;
	};

	vector<ull> sizes(n+1);
	vector<ull> path;
	path.reserve(300001);
	function<void(const ull n)> dfs = [&](const ull n) {
		if (nodes[n]->children.size() == 0) {
			for (ull i = 0; i < path.size(); i++) {
				//cout << n << ": " << path[i] << endl;
				bool found = false;
				for (ull j = 0; j < path.size(); j++) {
					if (i != j && (ancestor(path[i], path[j]) || ancestor(path[j], path[i]))) {
						found = true;
						cout << path[i] << " -> " << path[j] << endl;
						break;
					}
				}

				if (!found) {
					sizes[n]++;
				}
			}
			
		}
		else for (auto node : nodes[n]->children) {
			path.push_back(n);
			dfs(node->n);
			path.pop_back();
		}
	};
	dfs(1);
	cout << *max_element(sizes.begin(), sizes.end()) << endl;
}

int main() {
	ull t; cin >> t;
	while (t--) solve();
}
