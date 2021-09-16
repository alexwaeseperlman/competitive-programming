#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n; 
	string s; cin >> s;

	vector<int> types;
	for (int i = 0; i < s.size(); i++) types.push_back(s[i] - '0');

	int matrix[n][n];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) matrix[i][j] = 0;
	
	// unset = 0, draw = 1, win = 2, loss = 3, X = 4
	for (int i = 0; i < n; i++) {
		matrix[i][i] = 4;
		if (types[i] == 1) {
			for (int j = 0; j < n; j++) {
				if (j == i) continue;
				matrix[i][j] = 1;
				matrix[j][i] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (types[i] == 2) {
			bool found = false;
			for (int j = 0; j < n; j++) {
				if (j == i) continue;
				
				if (matrix[i][j] == 0) {
					found = true;
					matrix[i][j] = 2;
					matrix[j][i] = 3;
					break;
				}
			}
			if (!found) {
				cout << "NO" << endl;
				return;
			}
		}
	}

	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			switch (matrix[i][j]) {
				case 0: cout << "="; break;
				case 1: cout << "="; break;
				case 2: cout << "+"; break;
				case 3: cout << "-"; break;
				case 4: cout << "X"; break;
				default: cout << matrix[i][j]; break;
			}
		}
		cout << endl;
	}

}

int main() {
	ll t; cin >> t;
	while (t--) solve();
}
