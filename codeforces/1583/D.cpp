#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int anchor = 1;

	for (int i = 0; i < n-1; i++) {
		cout << "? ";
		for (int j = 0; j < n; j++) {
			if (j == n-1) cout << i+1 << " ";
			else cout << n << " ";
		}
		cout << endl;
		cout.flush();
		int r; cin >> r;
		if (r != 0) {
			anchor = n-i;
			if (i == n) anchor = 1;
			break;
		}
	}

	vector<int> order(n);
	order[n-1] = anchor;
	for (int i = 1; i <= n; i++) {
		if (anchor == i) continue;
		int av = 0, ov = 0;
		if (anchor > i) {
			av = 1; ov = anchor - i+1;
		}
		else {
			ov = 1;
			av = i - anchor+1;
		}

		cout << "? ";
		for (int j = 0; j < n; j++) {
			if (j == n-1) cout << av << " ";
			else cout << ov << " ";
		}
		cout << endl;
		cout.flush();
		int r; cin >> r;
		if (r == 0) continue;
		order[r-1] = i;
	}
	cout << "! ";
	for (int i= 0; i < order.size(); i++) cout<< order[i] << " ";
	cout << endl;
	cout.flush();

}
