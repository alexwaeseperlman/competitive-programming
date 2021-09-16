#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	string s; cin >> s;

	char c = 'a';
	ll start = -1;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] == 'a') {
			start = i;
			break;
		}
	}

	ll l = start, r = start;

	while (r - l < s.size()) {
		c++;
		if (l > 0 && s[l - 1] == c) l--;
		else if (r < s.size() - 1 && s[r + 1] == c) r++;
		else break;
	}

	if (l == 0 && r == s.size() - 1) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ll t; cin >> t;

	while (t--) solve();
}
