#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	int n = s.size();
	vector<vector<int>> psums(3, vector<int>(n+1));
	for (int i = 1; i <= n; i++) {
		psums[0][i] = psums[0][i-1];
		psums[1][i] = psums[1][i-1];
		psums[2][i] = psums[2][i-1];
		psums[s[i-1] - 'A'][i]++;
	}

	auto countCycle = [&](vector<int> &psum, int start, int size) {
		start = ((start - 1) % n)+1;
		int out = psum[min(n, start+size-1)] - psum[start-1];
		if (start + size - 1 > n) {
			out += psum[((start + size - 1) % n)];
		}
		return out;
	};

	int best = numeric_limits<int>::max();
	for (int a = 0; a < 3; a++) {
		for (auto [o, ex] : (vector<pair<int, int>>){ {(a+1)%3, (a+2)%3}, {(a+2)%3, (a+1)%3} }) {
			for (int i = 1; i <= n; i++) {
				int steps = 0;
				int astart = i, ostart = i + psums[a][n], exstart = i + psums[a][n] + psums[o][n];
				int acount = psums[a][n], ocount = psums[o][n], excount = psums[ex][n];
				int osInA = countCycle(psums[o], astart, acount), asInO = countCycle(psums[a], ostart, ocount);

				int missingAs = acount - countCycle(psums[a], astart, acount),
					missingOs = ocount - countCycle(psums[o], ostart, ocount);

				steps = missingAs + missingOs - min(asInO, osInA);

				//cout << i << " " << o << " " << ex << " " << steps << endl;
				if (steps < best) best = steps;
			}
		}
	}
	cout << best << endl;
}
