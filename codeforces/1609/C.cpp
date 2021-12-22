//#pragma GCC optimize "trapv" 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using namespace __gnu_pbds;

#define print(x) cout << #x << " " << x << endl;
#define print_array(x) (cout << #x); for (auto i : (x)) cout << " " << i; cout << endl;

template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ull gcd(ull a, ull b) {
	if (b > a) return gcd(a, b);
	if (b == 0) return a;
	return gcd(b, a%b);
}

bitset<1000001> notPrime;
vector<ll> primes;

ll count(vector<ll> &a) {
	ll total = 0, ones = 0;
	vector<pair<ll, ll>> counts;
	bool reset = false;
	for (ll i = 0; i < a.size(); i++) {
		if (notPrime[a[i]] && a[i] != 1) {
			if (counts.size() && !reset) {
				counts[counts.size()-1].second = ones;
			}
			ones = 0;
			reset = true;
		}
		else if (!notPrime[a[i]]) {
			if (!reset && counts.size()) counts[counts.size()-1].second = ones;
			counts.emplace_back(ones, 0);
			reset = false;
			ones = 0;
			//cout << ones <<" " <<a[i] << endl;
		}
		else {
			ones++;
		}
	}
	if (counts.size() && !reset) counts[counts.size()-1].second = ones;

	for (ll i = 0; i < counts.size(); i++) {
		total += (counts[i].first+1) * (counts[i].second+1)-1;
	}

	return total;
}

void solve() {
	ll n, e; cin >> n >> e;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	vector<vector<ll>> groups(e);
	for (ll i = 0; i < n; i++) {
		groups[i%e].push_back(a[i]);
	}

	ll total = 0;
	for (vector<ll> &i : groups) total += count(i);

	cout << total << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	notPrime[0] = true;
	notPrime[1] = true;
	for (ll i = 2; i <= 1000000; i++) {
		if (!notPrime[i]) {
			primes.push_back(i);
			for (ll j = 2*i; j <= 1000000; j += i) {
				notPrime[j] = true;
			}
		}
	}

	ll t; cin >> t;
	while (t--) solve();

}
