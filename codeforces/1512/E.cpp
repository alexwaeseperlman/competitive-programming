#include <iostream>
#include <set>
#include <vector>
using namespace std;

void solve() {
	int n, l, r, s;
	cin >> n >> l >> r >> s;

	int width = r - l + 1;

	vector<int> used;
	used.reserve(width);

	int sum = 0;
	for (int i = -width / 2; i < width - width / 2; i++) {
		used.push_back(i + s / width);
		sum += i + s / width;
	}
	
	while (sum < s) for (int i = used.size() - 1; i >= 0 && sum < s; i--) {
		sum++;
		used[i]++;
	}
	if (sum != s || used[0] <= 0 || used[used.size() - 1] > n) {
		cout << -1 << endl;
		return;
	}

	set<int> group;
	for (int i = 0; i < used.size(); i++) group.insert(used[i]);

	vector<int> numbers;
	int x = 1;
	for (int i = 1; i <= n; i++) {
		if (i >= l && i <= r) numbers.push_back(x);
		else {
			while (group.find(x) != group.end()) x++;
			numbers.push_back(x);
			x++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (i >= l && i <= r) {
			cout << used[i - l] << " ";
		}
		else cout << numbers[i - 1] << " ";
	}

	cout << endl;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) solve();
}
