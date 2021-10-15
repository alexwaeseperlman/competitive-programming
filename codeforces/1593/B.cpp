#include <bits/stdc++.h>
using namespace std;

void solve() {
	string n; cin >> n;

	auto count = [&](string n, string goal) -> int {
		int steps = 0, i=n.size()-1;
		for (; i >= 0 && n[i] != goal[1]; i--) {
			steps++;
		}
		i--;

		for (; i >= 0 && n[i] != goal[0]; i--) {
			steps++;
		}

		if (i == -1) return numeric_limits<int>::max();
		return steps;
	};

	cout << min(count(n, "00"), min(count(n, "25"), min(count(n, "50"), count(n, "75")))) << endl;

}

int main() {
	int t; cin >> t;

	while (t--) solve();
}
