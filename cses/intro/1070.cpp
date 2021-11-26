#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	if (n < 4) {
		if (n == 1) cout << 1 << endl;
		else cout << "NO SOLUTION" << endl;
		return 0;
	}

	int out = 1;
	for (int i = 0; i < n; i++) {
		cout << out + 1 << " ";
		out += 2;
		if (out % n < out) {
			out %= n;
			out -= ~n&1;
		}
	}
	cout << endl;
}
