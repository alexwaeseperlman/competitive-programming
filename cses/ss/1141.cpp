#include <bits/stdc++.h>
using namespace std;

int main() {
	multiset<int> song;
	int n; cin >> n;
	int m = 0, j = 0;
	vector<int> songs(n);
	for (int i = 0; i < n; i++) {
		cin >> songs[i];
		while (song.count(songs[i])) {
			song.erase(song.find(songs[j]));
			j++;
		}
		song.insert(songs[i]);
		m = max(m, i-j+1);
	}

	cout << m << endl;
}
