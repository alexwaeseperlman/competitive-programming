#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int pfixSum[100020];
int a[100020];

void solve() {
	int n;
	cin >> n;
	map<int, int> counts;
	counts[0] = 1;
	for (int i = 1; i <= n; i++) {
		char n; cin >> n;
		a[i] = n-'0';
		pfixSum[i] = pfixSum[i-1] + (a[i]-1);
		counts[pfixSum[i]]++;
	}

	ll total = 0;
	for (auto [x, c] : counts) {
		total += c*(c-1)/2;
	}

	cout << total << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
