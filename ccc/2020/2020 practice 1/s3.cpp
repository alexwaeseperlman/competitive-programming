#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

int _parent[50001][128];

struct edge {
	int u, v, k;
};

vector<edge> edges;

int parent(int i, int q) {
	if (_parent[i][q] == i) return i;
	_parent[i][q] = parent(_parent[i][q], q);
	return _parent[i][q];
}

bool connected(int i, int j, int q) {
	return parent(i, q) == parent(j, q);
}

void merge(int i, int j, int q) {
	_parent[parent(i, q)][q] = parent(j, q);
}

void build(int q) {
	for (int i = 0; i <= 50000; i++) _parent[i][q] = i;

	for (edge e : edges) {
		if ((e.k & (~q)) == 0) {
			merge(e.u, e.v, q);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, Q; cin >> N >> M >> Q;
	edges = vector<edge>(M);

	for (int i = 0; i < M; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].k;
	}
	for (int i = 0; i < 128; i++) {
		build(i);
	}

	for (int i = 0; i < Q; i++) {
		int a, b; cin >> a >> b;

		int x = 0;
		for (int j = 0; j < 128; j++) {
			x = j;
			if (connected(a, b, j)) {
				break;
			}
		}
		cout << x << endl;
	}

}
