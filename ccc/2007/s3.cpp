#include <bits/stdc++.h>

using namespace std;

const int N = 10000;

unordered_map<int, int> friends;
unordered_set<int> students;

unordered_map<int, int> groupLeaders;
unordered_map<int, int> groupLen;
unordered_map<int, unordered_map<int, int>> groups;

int main() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int j; cin >> j;
		cin >> friends[j];
		students.insert(j);
	}

	for (int i : students) {
		if (groupLeaders[i]) continue;
		int j = friends[i], d = 1;
		int steps = 0;

		while (j != i && steps < n+1) {
			steps++;
			j = friends[j];
		}

		if (steps == n+1) continue;
		else j = i;
		while (d == 1 || j != i) {
			groups[i][j] = d;
			groupLeaders[j] = i;
			groupLen[i]++;
			j = friends[j];
			d++;
		}
	}

	int i = 10, j = 10;
	while (true) {
		cin >> i >> j;
		if (i == 0 && j == 0) break;
		if (groupLeaders[i] != groupLeaders[j]) {
			cout << "No" << endl;
			continue;
		}
		int a = groups[groupLeaders[i]][j], b = groups[groupLeaders[i]][i];
		int l = groupLen[groupLeaders[i]];
		cout << "Yes " << (l + (a-b)%l)%l - 1 << endl;
	}
}
