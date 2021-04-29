#include <algorithm>
#include <functional>
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;
using ll = long long;

ll university[200001];
unordered_set<ll> usedUnis;
vector<ll> teams[200001];

void solve() {
	ll n;
	cin >> n;
	usedUnis.clear();
	
	for (ll i = 0; i < n; i++) {
		cin >> university[i];
		teams[i + 1].clear();
		usedUnis.insert(university[i]);
	}
	for (ll i = 0; i < n; i++) {
		int s;
		cin >> s;
		teams[university[i]].push_back(s);
	}

	for (ll i : usedUnis) {
		sort(teams[i].begin(), teams[i].end(), greater<ll>());
		for (ll j = 1; j < teams[i].size(); j++) {
			teams[i][j] = teams[i][j - 1] + teams[i][j];
		}
	}

	multimap<ll, vector<ll>*> sizes;
	for (ll i : usedUnis) {
		if (teams[i].size()) sizes.emplace(teams[i].size(), &teams[i]);
	}


	for (ll i = 1; i <= n; i++) {
		ll sum = 0;
		for (auto team = (sizes.lower_bound(i)); team != sizes.end(); ++team) {
			ll accepted = ((team->second->size()) / i) * i - 1;
			if (accepted >= 0) sum += (*team->second)[accepted];
		}
		cout << sum << " ";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) solve();
}

