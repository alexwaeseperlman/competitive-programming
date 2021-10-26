#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s; cin >> s;
	char c = accumulate(s.begin(), s.end(), 'z', [](char a, char b) -> char { return min(a, b); });

	cout << c << " ";
	for (char i : s) {
		if (i == c) {
			c = '0';
			continue;
		}
		cout << i;
	}
	cout << endl;

}

int main() {
	int t; cin >> t;
	while (t--) solve();

}
