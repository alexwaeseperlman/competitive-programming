#include <bits/stdc++.h>
using namespace std;
 
void solve() {
	string s; cin >> s;
	reverse(s.begin(), s.end());
 
	vector<char> chars;
	map<char, int> counts;
	set<char> unique;
	for (int i = 0; i < s.size(); i++) {
		if (!unique.count(s[i])) {
			unique.insert(s[i]);
			chars.push_back(s[i]);
		}
		counts[s[i]]++;
	}
 
	int l = 0;
	for (int i = 0; i < chars.size(); i++) {
		l += (counts[chars[i]] / (chars.size() - i));
	}
 
	reverse(s.begin(), s.end());
	reverse(chars.begin(), chars.end());
 
	string out = "", o = s;
	s = o.substr(0, l);
	auto x = chars.begin();
	while (x != chars.end()) {
		string newS = "";
		out += s;
		for (int j = 0; j < s.size(); j++) {
			if (*x != s[j]) {
				newS += s[j];
			}
		}
		s = newS;
		x++;
	}
	out += s;
 
	if (out == o) cout << o.substr(0, l) << " " << string(chars.begin(), chars.end()) << endl;
	else cout << -1 << endl;
}
 
int main() {
	int t; cin >> t;
	while (t--) solve();
}
