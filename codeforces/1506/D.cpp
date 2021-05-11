#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <memory>

using namespace std;
int solve() {
	unordered_map<int, int> counts;
	priority_queue<pair<int, int>> order;

	int n;
	cin >> n;

	int total = 0;
	
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		
		counts[k]++;
		total++;
	}

	for (auto count : counts) {
		if (count.second > 0) order.emplace(count.second, count.first);
	}

	while (order.size() > 1) {
		pair<int, int> first = order.top();
		order.pop();
		pair<int, int> second = order.top();
		order.pop();

		first.first--;
		second.first--;
		total -= 2;

		if (first.first > 0) order.push(first);
		if (second.first > 0) order.push(second);
	}
	return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
	int tests;
	cin >> tests;

	for (int i = 0; i < tests; i++) {
		cout << solve() << endl;
	}
}
