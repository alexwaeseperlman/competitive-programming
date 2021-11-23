#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull solve(ull t, ull k) {
	string s = to_string(t);
	reverse(s.begin(), s.end());

	vector<string> dp(s.size());
	vector<set<char>> dpdigs(s.size());

	dpdigs[0].insert(s[0]);
	dp[0] = s[0];
	ull place = 10;
	for (int i = 1; i < s.size(); i++) {
		if (dpdigs[i-1].size() < k || dpdigs[i-1].count(s[i]-'0')) {
			dp[i] = min(dp[i], dp[i] + place*(s[i]-'0'));
		}
	}

}

int main() {
	for (ull i = 100000000; i < 1000000000; i++) {
		cout << i << " " << solve(i, 2) << endl;
	}
	int t; cin >> t;

	while (t--) {
		ull n, k; cin >> n >> k;
		cout << solve(n, k) << endl;
	}
}
