#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int L[200005], R[200005];

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

	for (int i : t) {
		if (L[i] > 0 && R[i] > 0) {
			int m = min(L[i], R[i]);
			L[i] -= m;
			l -= m;
			R[i] -= m;
			r -= m;
		}
	}

	int cost = 0;
	for (int i : t) {
		int *larger;
		if (R[i] > 1) larger = &R[i];
		else larger = &L[i];
		
		int c = min((*larger / 2) * 2, R[i] > 1 ? r - l : l - r);
		if (c > 1) {
			//cout << "C: " << c << ", larger: " << *larger << endl;
			cost += c / 2;
			*larger -= c;
			if (larger == &R[i]) r -= c;
			else l -= c;
		}
	}
	//cout << l << " " << r << endl;

	return cost + abs(l - r) / 2 + (l + r) / 2;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) cout << solve() << endl;
}
