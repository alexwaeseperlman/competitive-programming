#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;

	vector<int> counts(256);
	vector<int> regions;
	string out = "";
	for (int i = 0; i < s.size(); i++) {
		counts[s[i]]++;
		bool sat = true;
		for (char i : {'A', 'T', 'C', 'G' }) {
			sat = sat && counts[i];
		}
		if (sat) {
			fill(counts.begin(), counts.end(), 0);
			regions.push_back(i);
			out += s[i];
		}
	}
	for (char i : {'A', 'T', 'C', 'G'}) if (counts[i] == 0) {
		out += i;
		break;
	}
	cout << out << endl;
}
