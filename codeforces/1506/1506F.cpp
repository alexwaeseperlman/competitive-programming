#include <iostream>
#include <set>
#include <cmath>
#include <vector>


using namespace std;

int dist(bool normal, pair<int, int> p) {
	if (!normal) {
		return dist(true, pair<int, int>(p.first + 2, p.second + 1));
	}
	if (p.first == p.second) return p.first - 1;

	int d = p.first - p.second + 1;

	return d / 2 - (d % 2 == 0);
}

void solve() {
	vector<int> rows;

	set<pair<int, int>> points{pair<int, int>(1, 1)};
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int r;
		cin >> r;
		rows.push_back(r);
	}
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		points.emplace(rows[i], c);
	}

	int d = 0;
	for (auto i = points.begin(); i != prev(points.end()); ++i) {
		int a = dist((i->first + i->second) % 2 == 0, pair<int, int>(next(i)->first - i->first + 1, next(i)->second - i->second + 1));
//		cout << i->first << " " << i->second << ", " << next(i)->first << " " << next(i)->second << ": " << a << endl;

		d += a;

	}

	cout << d << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) solve();
}
