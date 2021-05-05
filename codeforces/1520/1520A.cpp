#include <iostream>
#include <string>
using namespace std;

void solve() {
	bool started[26];
	for (int i = 0; i < 26; i++) started[i] = false;
	int n; cin >> n;

	string s;
	cin >> s;

	char p = s[0];
	started[p - 'A'] = true;
	for (int i = 1; i < s.size(); i++) {
		if (p != s[i] && started[s[i] - 'A']) {
			cout << "NO" << endl;
			return;
		}
		else started[s[i] - 'A'] = true;
		p = s[i];
	}

	cout << "YES" << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
