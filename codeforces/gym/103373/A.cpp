#include <bits/stdc++.h>
using namespace std;

using noc = pair<pair<int, pair<int, int>>, string>;

int main() {
	int n; cin >> n;
	vector<noc> nocs(n);
	for (int i = 0; i < n; i++) {

		cin >> nocs[i].first.first >> nocs[i].first.second.first >> nocs[i].first.second.second;
		getline(cin, nocs[i].second);
	}

	sort(nocs.begin(), nocs.end());

	cout << nocs[n-1].second.substr(1) << endl;

}
