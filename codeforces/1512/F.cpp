#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
	int n, c;
	cin >> n >> c;

	vector<ll> a, b;
	a.resize(n); b.resize(n-1);

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) cin >> b[i];

	ll rate, money = 0;
	ll computerTime = numeric_limits<ll>::max();
	ll time = 0;
	vector<ll> dp;
	dp.resize(n-1);

	for (int i = 0; i < a.size(); i++) {
		if (i > 0) {
			int dt = ((b[i-1] - money) + rate - 1) / rate;
			money = (money + rate * dt - b[i-1]);
			time += dt + 1;
		}
		rate = a[i];

		//cout << "rate at " << i << ": " << rate << ", c: " << c << ", time: " << time << ", computer time: " << (c + rate - 1) / rate << ", money: " << money << endl;

		if (time + ((c - money) + rate - 1) / rate < computerTime) computerTime = time + ((c - money) + rate - 1) / rate;
	}
	cout << computerTime << endl;
	
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
