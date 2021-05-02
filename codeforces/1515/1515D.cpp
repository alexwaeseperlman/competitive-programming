#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int L[200005], R[200005];
int removeMatching(int &l, int &r, unordered_set<int> &t) {
	int matched = 0;
	stack<pair<int, int>> matching;
	for (auto i : t) {
		if (L[i] > 0 && R[i] > 0) {
			matching.emplace(i, min(L[i], R[i]));
		}
	}
	while (!matching.empty()) {
		auto top = matching.top();
		//cout << top.first << " " << top.second << endl;
		matching.pop();
		L[top.first] -= top.second;
		R[top.first] -= top.second;
		l -= top.second;
		r -= top.second;
		matched += top.second;
	}
	
	return matched;
}

int solve() {
	int n, l, r;
	cin >> n >> l >> r;

	unordered_set<int> t;

	for (int i = 0; i <= n; i++) L[i] = 0, R[i] = 0;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		if (i < l) L[c]++;
		else R[c]++;
		t.insert(c);
	}

	// remove already matching pairs
	int matched = 0;
	matched += removeMatching(l, r, t);
	if (matched >= n / 2) return 0;

	int cost = 0;

	// move duplicates over until the length is the same
	for (int i : t) {
		int diff = min(abs(L[i] - R[i]) / 2, abs(l - r));
		//cout << "type: " << i << " diff: " << diff << endl;
		if (L[i] > 0) {
			R[i] = diff;
			r += diff;
			L[i] -= diff;
			l -= diff;
			cost += diff;
		}
		else if (R[i] > 0) {
			R[i] -= diff;
			r -= diff;
			L[i] = diff;
			l += diff;
			cost += diff;
		}
	}

	matched += removeMatching(l, r, t);

/*	cout << "L: ";
	for (auto i : t) cout << i << ": " <<L[i] << ", ";
	cout << endl;
	cout << "R: ";
	for (auto i : t) cout << i << ": " << R[i] << ", ";
	cout << endl;
	cout << l << " " << r << " " << cost << endl;*/

	return cost + abs(l - r) / 2 + (l + r) / 2;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) cout << solve() << endl;
}
