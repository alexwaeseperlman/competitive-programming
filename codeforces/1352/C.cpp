#include <iostream>

using namespace std;

int multiplesUnder(int n, int k) {
	return k / n;
}

void solve() {
	int n, k;
	cin >> n >> k;

	int delta = multiplesUnder(n, k);
	int pk = k;
	while (delta > 0) {
		k += delta;
		delta = multiplesUnder(n, k) - multiplesUnder(n, pk);
		pk = k;
	}

	cout << k << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) solve();
}
