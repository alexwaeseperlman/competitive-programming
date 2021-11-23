#include <bits/stdc++.h>
using namespace std;

struct line {
	int first, last;
	int shifts = 0;
	line(int first, int last, int shifts): first(first), last(last), shifts(shifts) {};
};

struct block {
	int sum = 0;
	vector<line> trainLines;
};

int main() {
	int n, m, q; cin >> n >> m >> q;
	vector<int> passengers(n), lineAt(n);
	vector<vector<int>> lines(m);
	for (int i = 0; i < n; i++) {
		int l; cin >> l;
		lineAt[i] = l;
		lines[l].push_back(i);
	}

	for (int i = 0; i < n; i++) cin >> passengers[i];

	int b = sqrt(n);
	vector<block> blocks(n/b, block{0, 
			vector<line>(m, line(numeric_limits<int>::max(), -1, 0))
			});
	for (int i = 0; i < n; i++) {
		blocks[i/b].sum += passengers[i];
		auto &x = blocks[i/b].trainLines[lineAt[i]];
		int idx = find(lines[lineAt[i]].begin(), lines[lineAt[i]].end(), i) - lines[lineAt[i]].begin();
		x.first = min(x.first, idx);
		x.last = max(x.last, idx);
	}

	auto shift = [&](int l, int r) {
		int bstart = (l+b-1)/b, bend = r/b;
		
	};

	auto getSum = [&](int l, int r) {
		int bstart = (l+b-1)/b, bend = r/b;
		int total = 0;
		for (int i = 0; i < min(r, bstart*b); i++) {
			total += passengers[i];
		}
	};


}
