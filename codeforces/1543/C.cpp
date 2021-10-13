#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ld = long double;
ld eps = 0.0000001;

ld wins(ld c, ld m, ld p, ld v, ld w, bitset<2> done=0) {
	if (done[0] && done[1]) return w;
	ld out = p*w;
	ld cadd = min(c, v), madd = min(m, v);

	if (!done[0]) {
		bitset<2> newDone = done;
		if (v+eps>= c) newDone[0] = true;
		out += c*wins(c-cadd, newDone[1] ? 0.0 : m+cadd/2.0, newDone[1] ? p+cadd : p+cadd/2.0, v, w+1.0, newDone);
	}
	if (!done[1]) {
		bitset<2> newDone = done;
		if (v+eps >= m) newDone[1] = true;
		out += m*wins(newDone[0] ? 0.0 : c+madd/2.0, m-madd, newDone[0] ? p+madd:p+madd/2.0, v, w+1.0, newDone);
	}

	return out;
}

void solve() {
	ld c, m, p, v; cin >> c >> m >> p >> v;
	cout << setprecision(10) << wins(c, m, p, v, 1.0) << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
