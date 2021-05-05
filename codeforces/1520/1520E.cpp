#include <iostream>
#include <string>
#include <limits>

using namespace std;
using ll = long long;

ll solve() {
	ll n;
	cin >> n;

	string s;
	cin >> s;

	ll total = 0;
	ll cdist = 0;
	for (ll i = 0; i < n; i++) {
		if (s[i] == '*') {
			cdist += i;
			total++;
		}
	}


	ll before = 0, after = total;

	ll minCost = numeric_limits<ll>::max();
	ll bestIdx;

	for (ll i = 0; i < n; i++) {
		ll cost = cdist - (before - 1) * before / 2 - (after - 1) * after / 2;
		if (s[i] == '*') cost -= before;
		//cout << "cost " << cost << ", before " << before << ", after " << after << ", cdist " << cdist << endl;
		if (cost < minCost) {
			minCost = cost;
			bestIdx = i;
		}
		if (s[i] == '*') {
			before++;
			after--;
		}
		cdist += before - after;
	}
	return minCost;

}

int main() {
	int t;
	cin >> t;
	while (t--) cout << solve() << endl;
}
