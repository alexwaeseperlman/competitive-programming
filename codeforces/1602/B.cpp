#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n), counts(n+1);
	vector<vector<int>> steps;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		counts[a[i]]++;
	}
	steps.push_back(a);

	auto done = [&]() -> bool {
		for (int i = 0; i < counts.size(); i++) {
			if (counts[i] != 0 && counts[i] != i) return false;
		}
		return true;
	};

	vector<int> na(n);
	auto sna = [&]() {
		for (int i = 0; i < n; i++) {
			na[i] = counts[steps[steps.size()-1][i]];
		}
	};
	sna();
	steps.push_back(na);
	while (!done()) {
		fill(counts.begin(), counts.end(), 0);
		for (int i = 0; i < n; i++) {
			counts[steps[steps.size()-1][i]]++;
		}

		sna();
		steps.push_back(na);
	}

	int q; cin >> q;

	for (int i = 0; i < q; i++) {
		int x, k; cin >> x >> k;

		cout << steps[min((int)steps.size()-1, k)][x-1] << endl;
	}
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
