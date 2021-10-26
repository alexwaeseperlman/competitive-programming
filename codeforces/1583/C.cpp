#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, m; cin >> n >> m;

	vector<vector<bool>> blocked(n, vector<bool>(m)), nd(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			blocked[i][j] = c == 'X';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0) nd[i][j] = false;
			else nd[i][j] = blocked[i-1][j] && blocked[i][j-1];
			//cout << nd[i][j] << " ";
		}
		//cout << endl;
	}

	vector<int> psum(m+1, 0), ndc(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) ndc[j] += nd[i][j];
	}

	for (int i = 1; i <= m; i++) {
		psum[i] = psum[i-1] + (ndc[i-1] == 0);
		//cout << psum[i] << " ";
	}
	//cout << endl;

	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int x1, x2; cin >> x1 >> x2;
		//cout << x1 << " " << x2 << " " << psum[x1] << " " << psum[x2] << endl;
		if ((psum[x2] - psum[x1-1] + (!!ndc[x1-1])) == (x2 - x1+1)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}
