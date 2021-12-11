#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, n; cin >> k >> n;
	vector<string> a(n);
	map<string, int> idxs;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) idxs[a[i]] = i;

	vector<vector<int>> ord(n, vector<int>(n));
	
	for (int i = 0; i < k; i++) {
		vector<string> x(n);
		for (int j = 0; j < n; j++) cin >> x[j];
		vector<vector<string>> eqs(1);
		eqs[0].push_back(x[0]);
		int eq = 0;
		for (int j = 1; j < n; j++) {
			if (x[j-1].compare(x[j]) > 0) {
				eqs.push_back(vector<string>());
				eq++;
			}
			eqs[eq].push_back(x[j]);
		}

		for (int j = 0; j < eqs.size()-1; j++) {
			for (int k = j+1; k < eqs.size(); k++) {
				for (string a : eqs[j]) {
					for (string b : eqs[k]) {
						ord[idxs[a]][idxs[b]] = 1;
						ord[idxs[b]][idxs[a]] = -1;
					}
				}
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) cout << "B";
			else if (ord[i][j] == 0) cout << "?";
			else if (ord[i][j] == 1) cout << "0";
			else if (ord[i][j] == -1) cout << "1";
		}
		cout << endl;
	}
}
