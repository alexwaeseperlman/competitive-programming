#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		if (c > 1) {
			a -= c - 1;
			c = 1;
		}
		if (a < 0) cout << "NO" << endl;
		else if (c && a % 2) cout << "YES" << endl;
		else if (c && a % 2 == 0) cout << "NO" << endl;
		else if (b % 2 && a % 2 == 0 && a >= 2) cout << "YES" << endl;
		else if (b % 2) cout << "NO" << endl;
		else if (b && a % 2) cout << "NO" << endl;
		else if (a % 2) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}
