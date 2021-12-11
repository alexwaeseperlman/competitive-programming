#include <bits/stdc++.h>
using namespace std;

int main() {
	ofstream out;
	ifstream in;
	out.open("convention.out");
	in.open("convention.in");

	int N, M, C; in >> N >> M >> C;

	vector<int> t(N);
	for (int i = 0; i < N; i++) in >> t[i];

	sort(t.begin(), t.end());

	auto possible = [&](int m) -> bool {
		int start = N-1, count = 1, cows = 1;
		for (int i = N-2; i >= 0; i--) {
			if (cows >= C || t[start] - t[i] > m) {
				count++;
				start = i;
				cows = 0;
			}
			cows++;
		}
		return count <= M;
	};

	int lb = 0, ub = 1000000001;

	while (lb < ub) {
		int m = (lb+ub)/2;

		if (possible(m)) ub = m;
		else lb = m+1;
	}
	out << lb << endl;
}
