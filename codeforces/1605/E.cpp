#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	vector<vector<int>> factors(n+1);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 2*i; j <= n; j++) {
			factors[i].push_back(j);
		}
	}


	vector<pair<int, int>> coefs(n+1);
	coefs[1].first = -1;
	coefs[1].second = -a[0];
	// The number of operations is abs(xb[1]) + abs(y) where x and y are constants
	int x = 0, y = 0;
	for (int i = 2; i <= n; i++) {
		coefs[i].second = b[i-1] - a[i-1];
		for (int j : factors[i]) {
			coefs[i].first += coefs[j].first;
			coefs[i].second += coefs[j].second;
		}

		x += abs(coefs[i].first);
		y += abs(coefs[i].second);
	}

	for (auto i : coefs) {
		cout << i.first << "," << i.second << " ";
	}
	cout << endl;

	int q; cin >> q;
	while (q--) {
		int xi; cin >> xi;

		cout << abs(x*xi) + y << endl;
	}






	

}
