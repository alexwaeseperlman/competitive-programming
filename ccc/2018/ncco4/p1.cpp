#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N; cin >> N;

	priority_queue<ll> pq;
	for (ll i = 0; i < N; i++) {
		ll x; cin >> x;
		pq.push(-x);
	}

	ll total = 0;
	while (pq.size() > 1) {
		ll t = pq.top();
		pq.pop();
		t += pq.top();
		pq.pop();
		total -= t;
		pq.push(t);
	}

	cout << total << endl;
}
