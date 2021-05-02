#include <iostream>
#include <limits>
#include <map>
#include <queue>
using namespace std;


int idxs[100001];
int sums[100001];
void solve() {
	int n, m, x;
	cin >> n >> m >> x;

	priority_queue<pair<int, int>> heights;
	priority_queue<pair<int, int>> towers;
	
	for (int i = 0; i < m; i++) towers.emplace(0, i);

	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		heights.emplace(h, i);
	}

	while (heights.size() > 0) {
		auto block = heights.top();
		heights.pop();
		auto tower = towers.top();
		towers.pop();

		tower.first -= block.first;
		idxs[block.second] = tower.second;
		towers.push(tower);
	}

	int maxHeight = numeric_limits<int>::lowest(), minHeight = numeric_limits<int>::max();
	while (towers.size()) {
		auto tower = towers.top();
		towers.pop();
		if (-tower.first > maxHeight) maxHeight = -tower.first;
		if (-tower.first < minHeight) minHeight = -tower.first;
	}

	if (maxHeight - minHeight > x) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		cout << idxs[i] + 1 << " ";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) solve();
}
