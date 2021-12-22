#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll base = 1000000007;

vector<int> factors;

int main() {
	ll sum = 0, n; cin >> n;
	for (ll i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			factors.push_back(i);
			if (i*i != n) {
				factors.push_back(n/i);
			}
		}
	}
	sort(factors.begin(), factors.end());
	ll j = 1;
	for (int i = 0; i < factors.size()-1; i++) {
		while (j < factors[i+1]) cout << j++ << " ";
		cout << endl;
	}
}
