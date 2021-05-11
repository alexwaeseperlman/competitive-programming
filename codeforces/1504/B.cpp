#include <iostream>

using namespace std;

bool a[300001];
bool b[300001];

bool solve() {
	int len;
	cin >> len;
	for (int j= 0; j < 2; j++) for (int i = 0; i < len; i++) {
		char c;
		cin >> c;
		if (j == 0) a[i] = c == '1';
		else b[i] = c == '1';
	}
	
	int counts[2] = {0, 0};
	for (int i = 0; i < len; i++) {
		counts[a[i]]++;
	}

	bool flipped = false;
	for (int i = len - 1; i >= 0; i--) {
		bool cursor = a[i] != flipped;
		if (cursor != b[i]) {
			//cout << "Comparing at " << i << " counts: " << counts[0] << " " << counts[1] << endl;
			if (counts[0] == counts[1]) flipped = !flipped;
			else return false;
		}
		counts[a[i]]--;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		if (solve()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
