#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int count(int lb, int ub, vector<int> &arr) {
	return lower_bound(arr.begin(), arr.end(), ub) - upper_bound(arr.begin(), arr.end(), lb);
}

void solve() {
	int n, m; cin >> n >> m;

	vector<int> a;

	for (int i = 0; i < n*m; i++) {
		int k; cin >> k;
		a.push_back(k);
	}

	map<int, queue<int>> b;
	for (int i = 0; i < n*m; i++) {
		b[a[i]].push(i);
	}

	vector<vector<int>> values(n, vector<int>(m, -1));
	int i = 0;
	for (auto iter = b.begin(); iter != b.end(); iter++) {
		for (int j = 0; j < iter->second.size(); j++) {
			values[i/m][i%m] = iter->first;
			i++;
		}
	}

	vector<int> indices(n*m);
	map<int, int> chair;
	for (int i = 0; i < n; i++) {
		for (int j = m-1; j >= 0; j--) {
			indices[i*m+j] = b[values[i][j]].front();
			//cout << values[i][j] << " #" << b[values[i][j]].front() << " goes to " << i << "," << j << endl;
			chair[b[values[i][j]].front()] = i*m+j;
			b[values[i][j]].pop();
		}
	}

	vector<vector<bool>> seated(n, vector<bool>(m,false));
	int total = 0;
	for (int i = 0; i < n*m; i++) {
		int row = chair[i] / m, column = chair[i] % m;
		for (int j = 0; j < column; j++) {
			total += seated[row][j];
		}
		seated[row][column] = true;
	}
	cout << total << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
	
}
