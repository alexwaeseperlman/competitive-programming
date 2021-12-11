#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> x(N);
	for (int i = 0; i < N; i++) cin >> x[i];

	vector<string> options = {"a", "b", "c", "ab", "bc", "ac", "abc"};
	set<tuple<int, int, int>> p;

	do {
		bool possible = true;
		// Find a single variable
		map<string, int> opts;
		for (int i = 0; i < N; i++) opts[options[i]] = x[i];

		map<string, int> sums;
		for (int i = 0; i < 1<<N; i++) {
			string t = "";
			int total = 0, idx=0;
			for (int m = 1; m <= i; m<<=1) {
				if (i&m) {
					total += x[idx];
					t = join(t, options[idx]);
				}
				idx++;
			}
			opts[idx]
			
		}

	} while (next_permutation(options.begin(), options.end()));
	cout << p.size() << endl;
}

int main() {
	int T; cin >> T;
	while (T--) solve();

}
