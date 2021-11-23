#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b; cin >> a >> b;
	int games = a+b;

	// with a going first
	auto pos = [&](int a, int b, int x) -> bool {
		int aServes = (games+1)/2, bServes = games/2;
		if (x > min(a, bServes) + min(b, aServes)) return false;
		//cout << x << " " << min(a, bServes) + min(b, aServes) << " " << (max(b-bServes, 0) + max(a-aServes, 0))  << endl;
		if (x < max(b-bServes, 0) + max(0, a-aServes)) return false;
		//cout << a << " " << b << " " << x << " " << (max(b-bServes,0)+max(a-aServes,0)) << endl;
		if ((x-(max(b-bServes,0)+max(a-aServes,0))) % 2 == 0) return true;
		return false;
	};

	vector<int> out;
	for (int i = 0; i <= games; i++) {
		if (pos(a, b, i) || pos(b, a, i)) out.push_back(i);
	}
	cout << out.size() << endl;
	for (int i  : out) cout << i << " ";
	cout << endl;

}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
