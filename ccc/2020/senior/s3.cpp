#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

const ull base = 36028797018963951;

int main() {
	string t, h; cin >> t >> h;

	vector<int> tl(26), counts(26);
	for (int i = 0; i < t.size(); i++) tl[t[i]-'a']++;

	ull hash = 0, n26 = 1;
	for (int i = 0; i < t.size()-1; i++) n26 = (n26 * 26) % base;
	unordered_set<int> used;
	for (int i = 0; i < h.size(); i++) {
		counts[h[i]-'a']++;
		if (i >= t.size()) {
			hash = (hash + (base - (n26 * (h[i-t.size()]-'a')%base)))%base;
			counts[h[i-t.size()] - 'a']--;
		}
		hash = ((hash*26)+h[i]-'a') % base;
		bool alleq = true;
		for (int j = 0; j < 26; j++){
			alleq = alleq && (tl[j] == counts[j]);
		}
		if (alleq) {
			used.insert(hash);
		}
	}

	cout << used.size() << endl;
}
