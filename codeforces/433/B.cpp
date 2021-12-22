#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	vector<ll> p(n+1), s(n+1);
	for (int i = 0; i < n; i++) {
		p[i+1] = p[i] + v[i];
		s[i] = v[i];
	}
	sort(s.begin(), s.end());
	for (int i = 1; i <= n; i++) {
		s[i] += s[i-1];
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int type, l, r; cin >> type >> l >> r;
		if (type == 1) cout << p[r] - p[l-1] << endl;
		else cout << s[r] - s[l-1] << endl;
	}


}
