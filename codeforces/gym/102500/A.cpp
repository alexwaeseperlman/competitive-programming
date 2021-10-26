#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, w; cin >> n >> w;

	vector<pair<int, int>> p(n);
	vector<double> avg(n, 1.0/w);
	for (int i = 0; i < n; i++) p[i].second = i;
	for (int i = 0; i < w; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int x; cin >> x;
			p[x].first++;

		}
	}


}
