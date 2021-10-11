#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
	ull n; cin >> n;
	vector<pair<ull, int>> order;
	for (ull i = 0; i < n; i++) {
		ull a, b; cin >> a >> b;
		order.emplace_back(a, 1);
		order.emplace_back(a+b, -1);
	}

	sort(order.begin(), order.end());
	
	map<ull, ull> d;
	ull pday = 0;
	int plin = 0;
	for (auto [day, change] : order) {
		d[plin] += day - pday;
		plin += change;
		pday = day;
	}

	for (ull i = 1; i <= n; i++) {
		cout << d[i] << " ";
	}
	cout << endl;
	
}
