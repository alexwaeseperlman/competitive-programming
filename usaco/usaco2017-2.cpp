#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll targets[100];
ll ids[100];

int main() {
	ll n; cin >> n;
	
	for (ll i = 0; i < n; i++) {
		ll k; cin >> k;
		targets[k - 1] = i;
	}

	for (ll i = 0; i < n; i++) {
		cin >> ids[i];
	}

	for (ll j = 0; j < n; j++) {
		ll idx = targets[j];
		cout << ids[idx] << endl;
	}
}
