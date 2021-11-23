#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <stack>
#include <functional>
using namespace std;
using ll = long long;

struct node {
	node* parent;
	vector<node*> children;
	int id, depth;
};

int main() {
	ifstream in;
	in.open("milkvisits.in");
	int N, M; in >> N >> M;

	vector<bool> types(N+1);
	for (int i = 1; i <= N; i++) {
		char c; in >> c;
		types[i] = c == 'H';
	}
	
	// Use farm #1 as the root node
	vector<pair<int, int>> edges(N-1);
	for (int i = 0; i < N-1; i++) {
		int X, Y; in >> X >> Y;
		edges[i] = {X, Y};
	}

	vector<int> Hparent(N+1), Gparent(N+1);
	for (int i = 1; i <= N; i++) {
		Hparent[i] = i;
		Gparent[i] = i;
	}

	function<int(int, vector<int>&)> parent = [&](int i, vector<int> &out) -> int {
		if (out[i] == i) return i;
		out[i] = parent(out[i], out);
		return out[i];
	};
	auto merge = [&](int i, int j, vector<int> &out) -> void {
		out[parent(i, out)] = parent(j, out);
	};

	auto components = [&](vector<int> &out, bool type) -> void {
		for (auto [i, j] : edges) {
			if (types[i] == type && types[j] == type) {
				merge(i, j, out);
			}
		}
	};
	components(Hparent, true);
	components(Gparent, false);

	ofstream outs;
	outs.open("milkvisits.out");
	for (int i = 0; i < M; i++) {
		int a, b; in >> a >> b;
		char c; in >> c;
		vector<int> &parents = c == 'H' ? Gparent : Hparent;
		bool out = parent(a, parents) != parent(b, parents);
		if (a == b) {
			outs << (types[a] == (c == 'H'));
		}
		else {
			outs << out;
		}
	}
	outs.close();
}
