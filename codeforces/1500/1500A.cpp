#include <iostream>
#include <unordered_map>

using namespace std;

void solve() {
	unordered_map<int, pair<int, int>> sums;
	int n;
	cin >> n;
	
	int arr[200001];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int sum = arr[i] + arr[j];
			auto c = sums.find(sum);
			if (c != sums.end()) {
				auto s = c->second;
				if (s.first != i && s.second != i && s.first != j && s.second != j) {
					cout << "YES" << endl;
					cout << s.first + 1 << " " << s.second + 1 << " " << i + 1 << " " << j + 1 << endl;
					return;
				}
			}
			else {
				sums.emplace(sum, pair<int, int>(i, j));
			}
		}
	}

	cout << "NO" << endl;
}

int main() {
	solve();
}
