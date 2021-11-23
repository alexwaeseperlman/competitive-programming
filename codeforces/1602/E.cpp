#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using ull = long long;
using namespace __gnu_pbds;

ull inversions(vector<ull> &x) {
	tree<ull, null_type, less_equal<ull>, rb_tree_tag, tree_order_statistics_node_update> visited;
	ull total = 0;
	for (int i = 0; i < x.size(); i++) {
		visited.insert(x[i]);
		total += visited.size()- visited.order_of_key(x[i]+1);
	}
	return total;
}

void solve() {
	ull n, m; cin >> n >> m;
	vector<ull> a(n), b(m), p(m), x;
	for (ull i = 0; i < n; i++) cin >> a[i];
	for (ull j = 0; j < m; j++) cin >> b[j];

	sort(b.begin(), b.end());

	function<void(ull,ull,ull,ull)> solve = [&](ull l, ull r, ull lb, ull rb) {
		if (lb > rb) return;
		if (l > r) {
			for (ull i = lb; i <= rb; i++) {
				p[i] = r;
			}
			return;
		}
		ull mid = (lb+rb)/2, after = 0, pi = l, best = numeric_limits<ull>::max();
		for (ull i = l; i <= r; i++) {
			if (a[i] > b[mid]) after++;
		}
		for (ull i = l; i <= r+1; i++) {
			if (after < best) {
				pi = i;
				best = after;
			}
			if (i <= r) {
				if (a[i] > b[mid]) {
					after++;
				}
				if (a[i] < b[mid]) {
					after--;
				}
			}
		}

		p[mid] = pi;
		solve(l, pi, lb, mid-1);
		solve(pi, r, mid+1, rb);
	};

	solve(0, n-1, 0, m-1);

	ull j = 0;
	for (ull i = 0; i < n; i++) {
		while (j < m && p[j] == i) {
			x.push_back(b[j]);
			j++;
		}
		x.push_back(a[i]);
	}

	while (j++ < m) x.push_back(b[j-1]);

	cout << inversions(x) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) solve();
}
