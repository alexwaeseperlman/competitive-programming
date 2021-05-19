#include <bits/stdc++.h>
using namespace std;
using ll = long long;

list<ll> cards;

int main() {
	ll n, q; cin >> n >> q;

	for (ll i = 0; i < n; i++) {
		ll k;
		cin >> k;
		cards.push_back(k);
	}

	while (q--) {
		ll c; cin >> c;

		ll i = 0;
		for (auto card = cards.begin(); card != cards.end(); card++) {
			if (*card == c) {
				cout << (i + 1) << " ";
				cards.erase(card);
				break;
			}
			i++;
		}

		cards.push_front(c);
	}
}
