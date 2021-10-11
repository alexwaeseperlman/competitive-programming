#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull base = 998244353;
ull pow2[300001];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	pow2[0] = 1;
	for (ull i = 1; i < 300001; i++) {
		pow2[i] = (pow2[i-1]*2) % base;
	}

	ull n; cin >> n;
	vector<pair<ull, ull>> a(n);
	for (ull i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());

	ull total = 0;
	for (ull i = 0; i < n-1; i++) {
		for (ull j = i+1; j < n; j++) {
			if (a[i] <= a[j]) {
				total += pow2[j-i-1];
				total %= base;
			}
		}
	}
	cout << total << endl;
}
