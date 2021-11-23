#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int last = 0;
	auto test = [&]() {
		last = 0;
		vector<int> b(a);

		for (int i = 0; i < n-1; i++) {
			int s = min(b[i], b[i+1]);
			b[i] -= s;
			b[i+1] -= s;
			if (b[i]) {
				break;
			}
			last++;
		}
		bool zero = true;
		for (int i : b) zero = zero && !i;
		return zero;
	};
	bool w = test();
	if (!w) {
		int l = last;
		if (l+1 < n) swap(a[last], a[last+1]);
		w = test();
		if (!w) {
			if (l+1 < n) swap(a[l], a[l+1]);
			if (l+2 < n) swap(a[l+1], a[l+2]);
			w = test();
			if (!w) {
				if (l+2 < n) swap(a[l+1], a[l+2]);
				if (l-1 >= 0) swap(a[l], a[l-1]);
				w = test();

			}
		}
	}
	if (w) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();

}
