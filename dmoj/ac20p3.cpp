#include <bits/stdc++.h>
using namespace std;
const int big = 10000000;

int main() {
	int _; cin >> _ >> _;
	string s, t; cin >> s >> t;
	vector<vector<int>> nextLetter(s.size(), vector<int>(26, big));

	auto r = [&](int x) -> int {
		if (x == 0) return s.size();
		return x;
	};

	vector<int> last(26, big);
	for (int i = s.size()*2-1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) {
			if (nextLetter[i%s.size()][j] == big || r((2*s.size() - i + nextLetter[i%s.size()][j])%s.size()) > r((2*s.size() - i + last[j])%s.size())) 
				nextLetter[i%s.size()][j] = last[j];
		}

		last[s[i%s.size()]-'a'] = i%s.size();
	}

	int i = last[t[0]-'a'];
	if (i == big) {
		cout << -1 << endl;
		return 0;
	}
	long long steps = i;
	for (char c : t.substr(1)) {
		steps += r((2*s.size() - i + nextLetter[i][c-'a'])%s.size());

		if (nextLetter[i][c-'a'] == big) {
			cout << -1 << endl;
			return 0;
		}

		i = nextLetter[i][c-'a'];
	}
	if (i == big) cout << -1 << endl;
	else cout << steps+1 << endl;
}
