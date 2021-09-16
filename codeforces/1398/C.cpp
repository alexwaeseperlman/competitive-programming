#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int pfixSum[100020];
int a[100020];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char n; cin >> n;
		a[i] = n-'0';
		pfixSum[i] = pfixSum[i-1] + a[i];
	}
	
	int count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n;) {
			if (pfixSum[j] - pfixSum[i-1] == j-i+1) {
				count++;
				j++;
			}
			else if (pfixSum[j] - pfixSum[i-1] > j-i+1) {
				j += (pfixSum[j] - pfixSum[i-1]) - (j-i+1);
			}
			else {
				j++;
			}
		}
	}
	cout << count << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
