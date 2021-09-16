#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	string s; cin >> s;

	int total = s[0] == '0';
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '0' && s[i-1] != '0') total++;

		if (total == 2) break;
	}

	cout << total << endl;

}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
