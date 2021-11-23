#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct query {
	ll l, r;

	query(ll l, ll r): l(l), r(r) {};
};

struct segtree {
	ll N;
	vector<ll> t, d;
	segtree(ll N): N(N) {
		t = vector<ll>(2*N+1);
		d = vector<ll>(2*N+1);
	}




};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	segtree tree(2000001);
	//cout << "done tree" << endl;

	int q; cin >> q;
	while (q--) {
		string s; cin >> s;
		if (s == "ADD") {
			ll k, p; cin >> k >> p;
			tree.add(k, p);
		}
		if (s == "ADDRANGE") {
			ll l, r; cin >> l >> r;
			tree.addRange(l, r);
		}
		if (s == "BUYAMT") {
			ll L; cin >> L;
			cout << tree.buyAmt(L).first << endl;
		}
		if (s == "BUYLOW") {
			ll L; cin >> L;
			cout << tree.buyLow(L) << endl;
		}
		if (s == "BUYHIGH") {
			ll L; cin >> L;
			cout << tree.buyHigh(L) << endl;
		}
		if (s == "COST") {
			ll L; cin >> L;
			cout << tree.qcost(L) << endl;
		}
		if (s == "NUMCONES") {
			cout << tree.count() << endl;
		}
		if (s == "TOTALCOST") {
			cout << tree.cost() << endl;
		}
		if (s == "PRINT") {
			tree.print(); cout << endl;
		}
	}
}
