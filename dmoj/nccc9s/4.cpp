#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct query {
	int l=0, r=0, i=0;
	int block = 0;

	bool operator<(const query &rhs) const {
		if (block < rhs.block) return true;
		else return block == rhs.block && r < rhs.r;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q; cin >> n >> q;
	vector<ll> a(n), results(q), counts(n+1);
	vector<set<int>> wc(n+2);
	int mc = 0;
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<query> queries(q);
	int sq = sqrt(q);
	for (int i = 0; i < q; i++) {
		cin >> queries[i].l >> queries[i].r;
		queries[i].l--;
		queries[i].r--;
		queries[i].block = queries[i].l/sq;
		queries[i].i = i;
	}

	sort(queries.begin(), queries.end());

	int l = queries[0].l, r = queries[0].r;
	int passes = 0;
	int max = 0;

	function<void(int, int)> pass = [&](int i, int type) -> void {
		passes++;
		int c = counts[a[i]];
	
		if (c && wc[c].count(a[i])) {
			wc[c].erase(a[i]);
		}
		if (c > 0) wc[c+type].insert(a[i]);
		if (c == mc) {
			if (c+type > c){
				mc++;
				max = a[i];
			}
			else if (c+type < c) {
				if (wc[c].size() == 0) {
					mc--;
					max = *wc[c-1].rbegin();
				}
				else max = *wc[c].rbegin();
			}
		}
		counts[a[i]] += type;
	};

	for (int i = l; i <= r; i++) {
		pass(i, 1);
	}

	for (query q : queries) {
		while (r < q.r) {
			r++;
			pass(r, 1);
		}
		while (r > q.r) {
			pass(r, -1);
			r--;
		}
		while (l < q.l) {
			pass(l, -1);
			l++;
		}
		while (l > q.l) {
			l--;
			pass(l, 1);
		}
		results[q.i] = max;
	}

	for (int i : results) cout << i << endl;


}
