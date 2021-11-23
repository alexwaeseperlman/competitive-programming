#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> segtree(1);
vector<vector<bool>> lazy(1);

void build() {
	while (segtree[segtree.size()-1].size() > 1) {
		int i = segtree.size()-1;
		segtree.push_back(vector<int>((segtree[i].size()+1)/2, numeric_limits<int>::max()));
		lazy.push_back(vector<bool>((segtree[i].size()+1)/2));
		for (int j = 0; j < segtree[i].size(); j++) {
			segtree[i+1][j/2] = min(segtree[i][j], segtree[i+1][j/2]);
		}
	}
}
int getVal(int i, int j) {
	if (lazy[i][j]) {
		segtree[i][j] = min(getVal(i-1, 2*j), getVal(i-1, 2*j+1));
		lazy[i][j] = false;
	}
	return segtree[i][j];
}

void update(int i, int v) {
	segtree[0][i] = v;
	for (int l = 1; l < segtree.size(); l++) {
		i/=2;
		lazy[l][i] = true;
	}
}

int query(int l, int r, int layer) {
	int out = numeric_limits<int>::max();
	if (l >= r) return out;
	else if (l+1 == r) return getVal(layer, l);

	if (l%2) {
		out = min(out, getVal(layer, l));
		l++;
	}

	if (r%2) {
		r--;
		out = min(out, getVal(layer, r));
	}

	return min(out, query(l/2, r/2, layer+1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M; cin >> N >> M;
	segtree[0] = vector<int>(N);
	lazy[0] = vector<bool>(N);
	for (int i = 0; i < N; i++) cin >> segtree[0][i];
	build();

	for (int i = 0; i < M; i++) {
		char q; cin >> q;
		int x, y; cin >> x >> y;
		if (q == 'M') update(x, y);
		else cout << query(x, y+1, 0) << endl;
	}
}
