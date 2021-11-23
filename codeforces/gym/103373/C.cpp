#include <bits/stdc++.h>
using namespace std;
#define print(x) cout << #x << " " << x << endl;
#define print_array(x) (cout << #x); for (auto i : (x)) cout << " " << i; cout << endl;

struct Tree {
	int s=0, e=0, x=0;
	Tree *l=0, *r=0;

	Tree() {
	}
	Tree(int s, int e, int x): s(s), e(e), x(x) {};
	Tree(int s, int e, int x, Tree *l, Tree *r): s(s), l(l), r(r), e(e), x(x) {};

	int *lookup(int i) {
		if (s == e) return &x;
		if (l) l->x += x;
		if (r) r->x += x;
		x = 0;

		return (i <= l->e ? l : r)->lookup(i);
	}

	void inc(int end) {
		if (s > end) return;
		if (e <= end) {
			x++;
			return;
		}

		if (r) r->inc(end);
		if (l) l->inc(end);
	}
};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> p(n), ix(n);
	vector<Tree> nt(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
		ix[p[i]] = i;
	}
	for (int i = 0; i < n; i++) nt[i] = Tree(i, i, ix[i]);

	while (n > 1) {
		for (int i = 0; i < n-1; i+=2) {
			// what memory leak
			nt[i/2] = Tree{nt[i].s, nt[i+1].e, 0, new Tree(nt[i]), new Tree(nt[i+1])};
		}
		if (n % 2 == 1) {
			nt[(n)/2] = Tree{nt[n-1].s, nt[n-1].e, 0, new Tree(nt[n-1]), 0};
		}
		n = (n+1)/2;
	}

	int s = 0;
	for (int i = 0; i < p.size(); i++) {
		cout << i << ": " << nt[0].lookup(i) - i << endl;
		s += abs(*nt[0].lookup(i) - i);
		swap(
		//cout << nt[0].lookup(i) << endl;
		nt[0].inc(ix[i]);
	}
	cout << s << endl;


}
