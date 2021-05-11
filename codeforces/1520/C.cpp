#include <cstdlib>
#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;
	if (n == 2) {
		cout << "-1" << endl;
		return;
	}

	int k = 2;
	const int mid = (n*n + 1) / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int v;
			if ((i + j) % 2 == 0) v = k / 2;
			else v = k / 2 + mid;
			cout << v << "	";
			k++;
		}
		cout << endl;
	}

	
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
