#include <bits/stdc++.h>
#include <execution>
using namespace std;

int main() {
	int n, q; cin >> n >> q;
	vector<int> s(n+1), counts(n+1);
	for (int i = 1; i <= n; i++) cin >> s[i];

	for (int i = 0; i < q; i++) {
		fill(execution::par, counts.begin(), counts.end(), 0);
		int l, r; cin >> l >> r;
		int best, bestCount = 0;
		for (int j = l; j <= r; j++) {
			counts[s[j]]++;
			if (counts[s[j]] > bestCount || (counts[s[j]] >= bestCount && s[j] > best)) {
				bestCount = counts[s[j]];
				best = s[j];
			}
		}
		cout << best << endl;
	}

}
