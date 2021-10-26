#include <bits/stdc++.h>
using namespace std;

struct state {
	int jumps=numeric_limits<int>::lowest();
	state* pstate;
	int idx;

	bool operator>(const state &rhs) const {
		return jumps < rhs.jumps;
	}
	bool operator<(const state &rhs) const {
		return jumps > rhs.jumps;
	}
};

void solve() {
	int n; cin >> n;
	vector<int> a(n+1), b(n+1), c(n+1);

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	vector<state> dp(n+1);
	vector<set<int>> changesOff(n+1);
	vector<bool> on(n+1, false);
	on[n] = true;
	dp[n] = {0, 0, n};
	priority_queue<pair<state, int>> range;
	range.emplace(dp[n], n);

	priority_queue<state> ends;

	for (int i = n; i > 0; i--) {
		dp[i].idx = i;

		if (!range.size()) continue;
		auto top = range.top();
		while (!on[top.second] && range.size()) {
			range.pop();
			top = range.top();
		}
		if (!range.size()) continue;
		if (top.second == 0) break;

		dp[i].pstate = &dp[top.second];
		dp[i].jumps = top.first.jumps+1;

		int maxEnd=i-a[i+b[i]]+b[i];
		on[i] = true;
		if (maxEnd <= 0) {
			ends.push({dp[i].jumps + 1, &dp[i], 0});
		}
		else if (maxEnd < i) {
			changesOff[min(maxEnd, n)].insert(i);
			range.emplace(dp[i], i);
		}

		for (int j : changesOff[i]) {
			on[j] = false;
		}
		changesOff[i].clear();
	}
	if (ends.size() == 0) {
		cout << -1 << endl;
		return;
	}

	state e = ends.top();
	state* endState = &e;
	vector<state> order;
	while (endState->pstate != endState) {
		order.push_back(*endState);
		endState = endState->pstate;
	}

	reverse(order.begin(), order.end());
	cout << order.size() << endl;
	for (state i : order) {
		cout << i.idx << " ";
	}
	cout << endl;

}

int main() {
	solve();
}
