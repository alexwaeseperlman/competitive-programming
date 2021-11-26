#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> solveFor(int n, int start, int mid, int end) {
	vector<pair<int, int>> out;
	if (n == 0) return out;
	for (pair<int, int> i : solveFor(n-1, start, end, mid)) {
		out.push_back(i);
	}
	out.emplace_back(start, end);
	for (pair<int, int> i : solveFor(n-1, mid, start, end)) {
		out.push_back(i);
	}
	return out;
}

int main() {
	int n; cin >> n;
	cout << ((1<<n) - 1) << endl;
	for (auto [i, j] : solveFor(n, 1, 2, 3)) {
		cout << i << " " << j << endl;
	}
}
