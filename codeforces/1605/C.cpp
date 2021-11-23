#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	vector<int> as(n+1), bs(n+1), cs(n+1);

	vector<pair<int, int>> na(n+1, {-1, -1});
	pair<int, int> nas;
	nas.first = -1;
	nas.second = -1;
	for (int i = 1; i < n+1; i++) {
		as[i] = as[i-1];
		bs[i] = bs[i-1];
		cs[i] = cs[i-1];
		if (s[i-1] == 'a') {
			if (nas.first > -1) {
				na[nas.first].second = i;
			}
			if (nas.second > -1) {
				na[nas.second].first = i;
			}
			nas.first = nas.second;
			nas.second = i;
		}
		if (s[i-1] == 'a') as[i]++;
		if (s[i-1] == 'b') bs[i]++;
		if (s[i-1] == 'c') cs[i]++;
	}

	int best = numeric_limits<int>::max();

	for (int i = 1; i <= n; i++) {
		if (s[i-1] != 'a') continue;
		auto test = [&](int pos) {
			int ac = as[pos] - as[i-1];
			if (ac > bs[pos] - bs[i-1] && ac > cs[pos] - cs[i-1]) {
				best = min(best, pos-i+1);
			}
		};
		if (na[i].first > i) test(na[i].first);
		if (na[i].second > i) test(na[i].second);
	}
	if (best == numeric_limits<int>::max()) cout << -1 << endl;
	else cout << best << endl;

}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
