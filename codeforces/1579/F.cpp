#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, d; cin >> n >> d;
	vector<bool> a(n), visited(n);
	for (int i = 0; i < n; i++) {
		int n; cin >> n;
		a[i] = n;
	}
	vector<int> dist(n, numeric_limits<int>::max());

	for (int i = 0; i < n; i++) {
		if (!visited[i] && !a[i]) {
			int t = 0;
			int j = i;
			while (!visited[j]) {
				visited[j] = true;
				dist[j] = t;
				t++;
				j = (n+j-d)%n;
				if (!a[j]) break;
			}
		}
	}

	int m = 0;
	for (int i : dist) m = max(m, i);

	if (m == numeric_limits<int>::max()) {
		cout << -1 << endl;
	}
	else cout << m << endl;

}

int main() {
	int t; cin >> t;
	while (t--) solve();

}
