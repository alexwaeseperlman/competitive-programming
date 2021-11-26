#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n-1);
	for (int i = 0; i < n-1; i++) cin >> a[i];
	sort(a.begin(), a.end());

	int m = -1;
	for (int i = 1; i < n-1; i++) {
		if (a[i] != a[i-1]+1) m = a[i]-1;
	}
	if (a[0] == 2) m = 1;
	else if (m == -1) m = n;
	cout << m << endl;
}
