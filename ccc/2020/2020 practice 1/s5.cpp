#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll counts[100001];

ll solve(vector<ll> &pipes, int start, ll l, ll L, ll s, ll S) {
	ll startS = S, startL = L;
	//cout << "solving with " << S << " " << L << endl;
	if (start >= pipes.size()) return 0;
	if (L == 0 && S == 0) return 0;
	if (S == 0) {
		for (int i = start; i < pipes.size(); i++) {
			L -= min((pipes[i]/l), L);
			//cout << pipes[i] << " " << L << endl;
		}
		return startL-L;
	}

	// place all the small sticks in
	for (int i = start; i < pipes.size(); i++) {
		counts[i] = min(S, pipes[i]/s);
		S -= min(S, pipes[i]/s);
	}

	ll diff = l-s;
	int i = start;
	// every time small sticks are encountered, replace them with big sticks
	for (; i < pipes.size(); i++) {
		//if (counts[i] == 0) break;
		if (counts[i] < pipes[i]/s) {
			ll more = min(pipes[i]/s - counts[i], S);
			//cout << "can add " << more << " more to the " << pipes[i] << " pipe" << endl;
			counts[i] += more;
			pipes[i] -= counts[i]*s;
			S -= more;
			ll ls = min(pipes[i]/l, L);
			pipes[i] -= ls*l;
			L -= ls;
			//cout << pipes[i] << " left" << endl;

			ll swaps = pipes[i] / diff;
			ll lower = min(S, L);
			S += min(swaps, lower);
			L -= min(swaps, lower);

			break;
		}
		ll swaps = min((pipes[i] - s*counts[i]) / diff, counts[i]);
		//cout << "originally put " << counts[i] << "x" << s << " in the " << pipes[i] << " pipe" << endl;
		//cout << "swapped " << swaps << " times " << endl;
		S += min(swaps, L);
		L -= min(swaps, L);
		if (L == 0) break;
	}

	return solve(pipes, i+1, l, L, s, S) + startS - S + startL - L;
}

int main() {
	ios_base::sync_with_stdio(true);
	cin.tie(0);
	ll a, A; cin >> a >> A;
	ll b, B; cin >> b >> B;
	ll m = 0, M; cin >> M;

	ll l=a, L=A, s=b, S=B;
	if (a < b) {
		l=b; L=B; s=a; S=A; 
	}

	vector<ll> lengths(M);
	for (int i = 0; i < M; i++) cin >> lengths[i];
	sort(lengths.begin(), lengths.end());
	cout << solve(lengths, 0, l, L, s, S) <<endl;
}
