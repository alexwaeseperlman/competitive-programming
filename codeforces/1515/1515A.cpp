#include <iostream>
#include <algorithm>

using namespace std;

int weights[100];
void solve() {
	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; i++) cin >> weights[i];
	sort(weights, weights + n);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += weights[i];
		if (sum == x) {
			if (i == n - 1) {
				cout << "NO" << endl;
				return;
			}
			swap(weights[i], weights[i + 1]);
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) cout << weights[i] << " ";
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) solve();
}
