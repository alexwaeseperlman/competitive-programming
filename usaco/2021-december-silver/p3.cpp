#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M;

ll open[5001], close[5001];
ll buf[10002];
void square(ll *x, ll mul, ll offset) {
	for (ll i = 0; i <= 5000; i++) {
		for (ll j = 0; j <= 5000; j++) {
			buf[i+j+offset] += x[i] * x[j] * mul;
		}
	}
}

int main() {
	cin >> N >> M;

	for (ll i = 0; i < N; i++) {
		ll x, y; cin >> x >> y;
		close[y]++;
		open[x]++;
	}

	square(open, 1, 0);
	square(close, -1, 1);

	cout << buf[0] << endl;
	for (ll i = 1; i <= 2*M; i++) {
		buf[i] = buf[i] + buf[i-1];
		cout << buf[i] << endl;
	}
}
