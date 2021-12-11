#include <bits/stdc++.h>
using namespace std;

string s;
struct sfix {
	int idx = 0;
	pair<int, int> rank;
	bool operator<(const sfix &rhs) const {
		return rank < rhs.rank;
	}
};

vector<int> sArray() {
	vector<sfix> out(s.size());
	vector<int> ranks(s.size());
	for (int i = 0; i < s.size(); i++) {
		out[i].idx = i;
		out[i].rank = { s[i], s[(i+1)%s.size()] };
	}

	for (int size = 2; (size>>1) <= s.size(); size <<= 1) {
		sort(out.begin(), out.end());
		int diff = 0;
		ranks[out[0].idx] = 0;
		for (int i = 1; i < s.size(); i++) {
			if (out[i].rank != out[i-1].rank) diff++;
			ranks[out[i].idx] = diff;
		}
		for (int i = 0; i < s.size(); i++) {
			out[i].rank = { ranks[out[i].idx], ranks[(out[i].idx+size)%s.size()] };
		}

	}

	vector<int> sArray(s.size());
	for (int i = 0; i < s.size(); i++) {
		sArray[i] = out[i].idx;
	}

	return sArray;
}

int main() {
	int k;
	cin >> s >> k;

	s += '$';

	for (int i : sArray()) {
		if (s.size() - i > k) {
			cout << s.substr(i, k) << endl;
			return 0;
		}
	}
}
