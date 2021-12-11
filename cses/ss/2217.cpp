#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> a(n), idx(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++){
		a[i]--;
		idx[a[i]] = i;
	}

	int steps = 0;
	for (int i = 0; i < n-1; i++) {
		steps += idx[i+1] < idx[i];
	}

	while (m--) {
		int i, j; cin >> i >> j;
		i--;j--;

		swap(a[i], a[j]);
		for (int i : a) cout << i << " ";
		cout << endl;
		cout << steps << endl;
	}
}
