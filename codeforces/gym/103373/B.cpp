#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1000001;
bitset<N> notPrime;
vector<ll> sums(N, 1);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T; cin >> T;

	for (ll i = 2; i < N; i++) {
		if (!notPrime[i]) {
			for (ll j = 2*i; j < N; j += i) {
				notPrime[j] = true;
				ll d = i;
				while (j % d == 0) {
					d *= i;
				}
				sums[j] *= (d-1)/(i-1);
			}
		}
	}

	for (ll i = 0; i < T; i++) {
		ll n; cin >> n;
		if (sums[n] > 2*n) cout << "abundant";
		else if (sums[n] < 2*n) cout << "deficient";
		else cout << "perfect";
		cout << endl;
	}
}
