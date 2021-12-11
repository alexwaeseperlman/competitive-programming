#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	vector<int> a(t);
	while (t--) cin >> a[t];
	set<int> s;
	for (int i : a) s.insert(i);
	cout << s.size() << endl;
}
