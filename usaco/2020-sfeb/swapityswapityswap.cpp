#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream in;
	ofstream out;
	in.open("swap.in");
	out.open("swap.out");
	int N, M, K; in >> N >> M >> K;

	vector<int> idxs(N), op(N);
	for (int i = 0; i < N; i++) idxs[i] = i;
	copy(idxs.begin(), idxs.end(), op.begin());

	for (int i = 0; i < M; i++) {
		int l, r; in >> l >> r;
		reverse(op.begin()+l-1, op.begin()+r);
	}

	auto apply = [&](const vector<int> &target, const vector<int> &idxs) {
		vector<int> out(target.size());
		for (int i = 0; i < target.size(); i++) {
			out[i] = target[idxs[i]];
		}
		return out;
	};
	while (K) {
		if (K&1) {
			idxs = apply(idxs, op);
		}
		op = apply(op, op);
		K >>= 1;
	}

	for (int i : idxs) out << i+1 << endl;
}
