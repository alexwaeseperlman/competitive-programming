#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> touches(n);

	map<int, int> left, right;
	map<int, pair<int, int>> pos;
	set<int> taken;

	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		right[r] = i;
		left[l] = i;
		pos[i] = {l, r};
	}

	int p; cin >> p;
	for (int i = 0; i < p; i++) {
		int x; cin >> x;
		taken.insert(x);
		if (right.count(x) && left.count(x)) {
			touches[right[x]]++;
			touches[left[x]]++;
		}
		else {
			auto c = right.lower_bound(x);
			if (c != right.end() && pos[c->second].first <= x && pos[c->second].second >= x) {
				touches[c->second]++;
			}
		}
	}
	//for (int i = 0; i < n; i++) cout << touches[i] << " ";
	//cout << endl;
	for (int i = 0; i < n; i++) {
		if (touches[i] > 2) {
			cout << "impossible" << endl;
			return 0;
		}
	}
	vector<int> out;
	for (int i = 0; i < n-1; i++) {
		if (touches[i] < 2 && touches[i+1] < 2 && left[pos[i].second] == i+1 && !taken.count(pos[i].second)) {
			taken.insert(pos[i].second);
			out.push_back(pos[i].second);
			touches[i]++;
			touches[i+1]++;
		}
	}
	for (int i = 0; i < n; i++) {
		while (touches[i] < 2) {
			int p = pos[i].second-1;
			while (taken.count(p)) p--;
			out.push_back(p);
			taken.insert(p);
			touches[i]++;
		}
	}

	cout << out.size() << endl;
	for (int i : out) cout << i << " ";
	cout << endl;



}
