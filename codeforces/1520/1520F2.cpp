#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

map<int, map<int, int>> queries;

void updateAnswer(int answer) {
	for (auto i = queries.begin(); i != queries.upper_bound(answer); i++) {
		for (auto j = i->second.lower_bound(answer); j != i->second.end(); j++) {
			j->second++;
		}
	}
}

int query(int lb, int ub) {
	if (queries.find(lb) != queries.end() && queries[lb].find(ub) != queries[lb].end()) return queries[lb][ub];
	cout << "? " << lb << " " << ub << endl;
	cout.flush();
	int sum;
	cin >> sum;
	queries[lb][ub] = sum;
	return sum;
}

void solve(int n) {
	int k;
	cin >> k;
	int lb = 1, ub = n;
	int zeros;

	int sum = query(1, ub);
	zeros = n - sum;

	while (ub - lb >= 1) {
		int i = (ub + lb) / 2;
		int sum = query(1, i);
		int targetSum = i;
		zeros = targetSum - sum;
		
		if (zeros < k) lb = i + 1;
		else ub = i;
	}

	cout << "! " << lb << endl;
	updateAnswer(lb);
}

int main() {
	int n, t;
	cin >> n >> t;

	while (t--) solve(n);

}
