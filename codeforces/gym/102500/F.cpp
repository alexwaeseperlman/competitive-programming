#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int getOwner(int x) {
	if (parent[x] == x) return x;
	parent[x] = getOwner(parent[x]);
	return parent[x];
}
bool connected(int a, int b) {
	return getOwner(a) == getOwner(b);
}
void unionSets(int a, int b) {
	parent[getOwner(a)] = getOwner(b);
}

struct relation {
	int p, q, r;
};

int main() {
	int n; cin >> n;
	map<int, vector<int>> edges;
	for (int i = 0; i < n; i++) {
		parent.push_back(i);
		int m; cin >> m;
		for (int j = 0; j < m; j++) {
			int d; cin >> d;
			edges[d].push_back(i);
		}
	}

	vector<relation> rs;
	for (auto [i, group] : edges) {
		for (int j = 1; j < group.size(); j++) {
			for (int d = j; d < group.size(); d += j) {
				if (!connected(group[0], group[d])) {
					unionSets(group[0], group[d]);
					rs.push_back(relation{group[0], group[d], i});
				}
			}
		}
	}

	//bool fc = true;
	//for (int i = 1; i < n; i++) {
		//fc = fc && connected(0, i);
	//}
	if (rs.size() == n-1) {
		for (int i = 0; i < rs.size(); i++) {
			cout << rs[i].p+1 << " " << rs[i].q+1 << " " << rs[i].r << endl;
		}
	}
	else cout << "impossible" << endl;

}
