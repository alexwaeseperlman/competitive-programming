#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll N, M; cin >> N >> M;
	vector<pair<ll, ll>> d(M);
	for (ll i = 0; i < M; i++) cin >> d[i].first >> d[i].second;

	sort(d.begin(), d.end());

	for (auto [
}
