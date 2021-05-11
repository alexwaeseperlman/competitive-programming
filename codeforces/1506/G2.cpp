#include <iostream>
#include <string>
 
using namespace std;
 
int counts[26];
int lastIdxs[26];
 
void solve() {
	for (int i = 0; i < 26; i++) counts[i] = 0;
 
	string s;
	string out;
 
	cin >> s;
 
	for (int i = 0; i < s.size(); i++) {
		counts[s[i] - 'a']++;
		lastIdxs[s[i] - 'a'] = i;
	}
 
	for (int i = 0; i < s.size(); i++) {
		if (counts[s[i] - 'a'] < 1) continue;
		if (counts[s[i] - 'a'] > 1 && i != lastIdxs[s[i] - 'a']) {
			char max = s[i];
			for (int j = i + 1; j < s.size(); j++) {
				if (counts[s[j] - 'a'] > 0 && s[j] > max) max = s[j];
				if (counts[s[j] - 'a'] >= 1 && lastIdxs[s[j] - 'a'] == j && s[j] < max) break;
			}
			if (max > s[i]) continue;
		}
 
		out += s[i];
		counts[s[i] - 'a'] = 0;
	}
 
	cout << out << endl;
}
 
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) solve();
 
	return 0;
}
