#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = unsigned long long;

ll sqrt(ll n) {
	ll ub = min(2147483648ull, n), lb = 1ull;

	while (ub - lb > 1) {
		ll x = (ub + lb) / 2;
		if (x * x > n) ub = x;
		else if (x * x < n) lb = x;
		else return x;
	}
	return lb;
}

ll S(ll N, ll mod) {
	ll i = sqrt(N);
	vector<ll> added;
	added.reserve(i + 1);

	ll sum = 0;

	for (; i*i >= 1ull; i--) {
		ll currentSquareCount = N / (i*i);

		ll j = 2ull;
		while (j*j*i*i <= N) {
			currentSquareCount -= added[j*i];
			j++;
		}
		added[i] = currentSquareCount;
		sum += ((currentSquareCount % mod) * (i * i % mod)) % mod;
	}
	return sum % mod;
}

int main() {
	ll N, mod;

	cin >> N >> mod;

	cout << S(N, mod) << endl;

}
