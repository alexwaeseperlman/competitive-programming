//#pragma GCC optimize "trapv" 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using namespace __gnu_pbds;

#define print(x) cout << #x << " " << x << endl;
#define print_array(x) (cout << #x); for (auto i : (x)) cout << " " << i; cout << endl;

template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ull gcd(ull a, ull b) {
	if (b > a) return gcd(a, b);
	if (b == 0) return a;
	return gcd(b, a%b);
}

struct comment {
	int j;
	bool c;

};

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<comment>> comments(n+1);
	vector<bool> visited(n+1), imposter(n+1);

	for (int _ = 0; _ < m; _++) {
		int i; cin >> i;
		comment c; cin >> c.j;
		string s; cin >> s;
		c.c = s == "imposter";

		comments[i].push_back(c);
		comments[c.j].push_back(comment{i, c.c});
	}

	function<int(int)> getVal = [&](int p) -> int {
		int imposters = 0, steps = 0;
		queue<pair<bool, int>> bfs;
		bfs.emplace(false, p);

		while (bfs.size()) {
			auto [imp, id] = bfs.front();
			bfs.pop();
			if (visited[id] && imposter[id] != imp) return -1;
			else if (visited[id]) continue;
			else {
				visited[id] = true;
				imposter[id] = imp;
			}
			for (comment c : comments[id]) {
				bfs.emplace(imp ^ c.c, c.j);
			}
			steps++;
			if (imp) imposters++;
		}
		return max(imposters, steps-imposters);
	};
	int total = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			int v = getVal(i);
			if (v == -1) {
				cout << -1 << endl;
				return;
			}
			total += v;
		}
	}

	cout << total << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) solve();

}
