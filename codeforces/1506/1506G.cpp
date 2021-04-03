#include <iostream>
#include <string>
#include <set>

using namespace std;

set<int> letterIdxs[26];

void solve() {
	for (int i = 0; i < 26; i++) {
		letterIdxs[i] = set<int>();
	}

	string s;
	string out;

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		letterIdxs[s[i] - 'a'].insert(i);
	}

	for (int i = 0; i < s.size(); i++) {
		if (letterIdxs[s[i] - 'a'].size() < 1) continue;
		if (letterIdxs[s[i] - 'a'].size() > 1 && i != *letterIdxs[s[i] - 'a'].rbegin()) {
			int forced = s.size();
			for (int j = 0; j < 26; j++) {
				if (j == s[i] - 'a') continue;

				auto n = letterIdxs[j].rbegin();
				if (letterIdxs[j].size() >= 1 && *n < forced) forced = *n;
			}
			char max = s[i];
			for (int j = 0; j < 26; j++) {
				if (letterIdxs[j].size() == 0 || j + 'a' == s[i]) continue;
				int closestIdx = *letterIdxs[j].lower_bound(i + 1);
				
				if (j + 'a' >= max && closestIdx <= forced) {
					max = j + 'a';
				}
			}
			if (max > s[i]) {
				letterIdxs[s[i] - 'a'].erase(i);
				continue;
			}
		}

		out += s[i];
		letterIdxs[s[i] - 'a'].clear();
	}

	cout << out << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) solve();

	return 0;
}
