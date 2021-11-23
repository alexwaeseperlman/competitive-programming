#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

void solve() {
	string s;
	cin >> s;

	int ab = 0, ba = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == 'b' && s[i-1] == 'a') ab++;
		if (s[i] == 'a' && s[i-1] == 'b') ba++;
	}

	if (ab == ba) {
		cout << s << endl;
		return;
	}
	s[s.size()-1] = 'a' + (s[s.size()-1] == 'a');
	cout << s << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();

}
