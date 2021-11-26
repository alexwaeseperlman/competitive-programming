#include <bits/stdc++.h>
using namespace std;

int main() {
	string k; cin >> k;
	vector<string> a;
	sort(k.begin(), k.end());
	do {
		a.push_back(k);
	} while (next_permutation(k.begin(), k.end()));

	cout << a.size() << endl;
	for (string s : a) cout << s << endl;
}
