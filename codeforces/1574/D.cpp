#include <bits/stdc++.h>

using namespace std;

struct Node {
	map<int, Node*> children;
	int n;
	Node(int n): n(n) {

	}
	Node(int n, vector<vector<int>> &seqs): n(n) {
		for (int i = 0; i < seqs.size(); i++) {
			add(seqs[i]);
		}
	}
	
	bool test(vector<int> &seq, int i=0) {
		if (i == seq.size()) return true;
		if (!children[seq[i]]) return false;
		else return children[seq[i]]->test(seq, i+1);
	}

	void add(vector<int> &seq, int i=0) {
		if (i == seq.size()) return;
		if (!children[seq[i]]) children[seq[i]] = new Node(n-1);
		children[seq[i]]->add(seq, i+1);

	}
};

int main() {
	int n; cin >> n;
	vector<vector<int>> slots(n);
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int l; cin >> l;
			slots[i].push_back(l);
		}
	}
	

	priority_queue<pair<int, vector<int>>> dfs;
	vector<int> top(n);

	function<int(vector<int>&)> score = [&](vector<int> &top) -> int {
		int total = 0;
		for (int i = 0; i < n; i++) total += slots[i][top[i]-1];

		return total;
	};

	for (int i = 0; i < n; i++) top[i] = slots[i].size();

	dfs.emplace(score(top), top);

	int m; cin >> m;
	vector<vector<int>> builds(m, vector<int>(n));
	while (m--) {
		for (int i = 0; i < n; i++) cin >> builds[m][i];
	}

	Node *t = new Node(n, builds);
	Node *v = new Node(n);

	while (dfs.size() && dfs.size() < 1000000000) {
		if (!t->test(top)) break;
		for (int i = 0; i < n; i++) {
			if (top[i] <= 1) continue;
			top[i]--;
			if (!v->test(top)) {
				dfs.emplace(score(top), top);
				v->add(top);
			}
			top[i]++;
		}
		dfs.pop();
		top = dfs.top().second;
	}

	for (int i = 0; i < n; i++) cout << top[i] << " ";
	cout << endl;
}
