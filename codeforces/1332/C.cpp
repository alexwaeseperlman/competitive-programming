#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		int out = 0;
		for (int i = 0; 2*i < k; i++) {
			vector<int> counts(26);
			for (int j = i; j < n; j += k) {
				counts[s[j]-'a']++;
			}
			if (k-i-1 != i) for (int j = k-i-1; j < n; j += k) {
				counts[s[j]-'a']++;
			}
			int high = 0, sum = 0;
			for (int j = 0; j < 26; j++) {
				if (counts[j] > high) high = counts[j];
				sum += counts[j];
			}
			out += sum - high;
		}
		cout << out << endl;
	}



}
