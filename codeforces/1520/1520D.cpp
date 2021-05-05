#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>


using ll = long long;
using namespace std;

void solve() {
	ll n;
	cin >> n;

	ll arr[n];
	unordered_map<ll, ll> offsets;

	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		offsets[arr[i] - i - 1]++;
	}

	ll total = 0;
	for (pair<ll, ll> i : offsets) {
		total += (i.second - 1) * i.second / 2;
	}

	cout << total << endl;

}

int main() {
	int t;
	cin >> t;

	while (t--) solve();
}
