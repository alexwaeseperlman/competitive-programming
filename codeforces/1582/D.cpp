#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	if (b > a) return gcd(b, a);

	return gcd(b, a%b);

}

void solve() {
	ll n; cin >> n;
	vector<pair<ll, ll>> a(n);
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.begin(), a.end(), [](const pair<ll, ll> a, const pair<ll, ll> b) -> bool {
		return a.first > b.first;
	});

	vector<ll> c(n);
	set<pair<ll, ll>> unique;
	unique.insert(a[0]);
	unique.insert(a[1]);
	sum += a[0].first + a[1].first;
	for (int i = 2; i < n; i++) {
		if (a[i].second < n-1 && a[i].first == a[i+1].first) {
			c[a[i].second] = -1;
			c[a[i+1].second] = 1;
			i++;
			continue;
		}
		unique.insert(a[i]);
		sum += a[i].first;
	}

	for (auto [x, i] : unique) {
		if (sum-x == 0) continue;
		ll m = gcd(abs(sum-x), abs(x));
		ll constant = abs((sum-x)/m), add = abs(x/m);
		ll total = add*(unique.size()-1ull) + constant;
		if (total + n - unique.size() <= 1000000000ull) {
			ll sign = (x * (sum-x)) < 0 ? 1 : -1;
			for (int j = 0; j < n; j++) {
				if (c[j] == 0) {
					if (j == i) {
						c[j] = sign*constant;
					}
					else {
						c[j] = add;
					}
				}
			}
			break;
		}
	}

	for (int j = 0; j < n; j++) {
		cout << c[j] << " ";
	}
	cout << endl;

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll t; cin >> t;
	while (t--) solve();

}
