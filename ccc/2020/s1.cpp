#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll N; cin >> N;
	vector<pair<ll, ll>> obs(N);
	while (N--) cin >> obs[N].first >> obs[N].second;
	sort(obs.begin(), obs.end());

	double s = 0;
	for (ll i = 0; i < obs.size()-1; i++) {
		s = max(s, (double)abs(obs[i+1].second - obs[i].second)/(double)(obs[i+1].first - obs[i].first));
	}

	cout << s << endl;
		
}
