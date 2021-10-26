#include <bits/stdc++.h>
using namespace std;

bool palindrome(string &s, char without) {
	int x = s.size()-1;
	for (int i = 0; i < s.size() && x > i && x >= 0; i++, x--) {
		while (i < s.size() && s[i] == without) i++;
		while (x >= 0 && s[x] == without) x--;
		if (s[i] != s[x]) return false;
	}
	return true;
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int best = numeric_limits<int>::max();

	if (palindrome(s, 0)) cout << 0 << endl;
	else {
		for (char c = 'a'; c <= 'z'; c++) {
			if (palindrome(s, c)) {
				int x = s.size()-1, rs = 0;
				for (int i = 0; i < s.size() && x >= 0 && x > i; i++, x--) {

					while (i < s.size() && x >= 0 && s[i] == c && s[x] == c) {
						x--;
						i++;
					}

					while (i < s.size() && s[i] == c) {
						i++;
						rs++;
					}
					while (x >= 0 && s[x] == c) {
						x--;
						rs++;
					}
				}
				best = min(best, rs);
			}
		}
		if (best == numeric_limits<int>::max()) cout << -1 << endl;
		else cout << best << endl;
	}



	
}

int main() {
	int t; cin >> t;
	while (t--) solve();

}
