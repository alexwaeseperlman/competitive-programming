#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, K;

pair<ll, ll> patches[200001];
ll nhojCows[200001];
int owner[200001];
ll between[200002][3];
ll psum[200002];
ll last[200002];

ll pointSum(ll p) {
	ll lb = 0, ub = M;
	while (lb < ub) {
		ll m = (lb+ub)/2;
		if (nhojCows[m] > p) ub = m;
		else lb = m+1;
	}
	ll start = (nhojCows[lb] + p)/2, end = (nhojCows[lb+1] + p)/2;

	ll total = 0;
	lb = 0, ub = K;
	while (lb < ub) {
		ll m = (lb+ub)/2;
		if (patches[m].first < start) lb = m+1;
		else ub = m;
	}
	ll firstIdx = lb;
	lb = 0, ub = K;
	while (lb < ub) {
		ll m = (lb+ub)/2;
		if (patches[m].first > end) lb = m+1;
		else ub = m;
	}
	ll secondIdx = lb;
	return psum[secondIdx+1] - psum[firstIdx-1];
}

ll sumNearest(ll lb, ll ub) {
	if (lb >= ub) return pointSum(lb);
	ll m1 = (2*lb+ub)/3, m2 = (lb+2*ub)/3;
	if (pointSum(m1) > pointSum(m2)) return sumNearest(lb, m2-1);
	else if (pointSum(m1) < pointSum(m2)) return sumNearest(m1+1, ub);
	return sumNearest(m1, m2);
}

int main() {
	cin >> K >> M >> N;

	for (int i = 0; i < K; i++) {
		cin >> patches[i].first >> patches[i].second;
	}
	sort(patches, patches+K);

	for (int i = 0; i < M; i++) {
		cin >> nhojCows[i];
	}
	sort(nhojCows, nhojCows + M);

	int i = 0, j = 0;
	while (i < M) {
		while (patches[j].first <= nhojCows[i]) {
			owner[j] = i;
			last[i] = j;
			j++;
		}
		i++;
	}
	while (j < K) {
		owner[j] = i;
		last[i] = j;
		j++;
	}

	ll prev = 0;
	priority_queue<ll> x;
	for (ll i = 1; i <= K; i++) {
		psum[i] += psum[i-1];
		if (i > 1 && owner[i-1] != owner[i-2]) prev = psum[i-1];
		psum[i] += patches[i-1].second;
		between[owner[i-1]][2] = psum[i] - prev;
		x.push(between[owner[i-1]][2]);
	}
	between[0][1] = between[0][2];
	between[M][1] = between[M][2];

	for (ll i = 0; i < M-1; i++) {
		between[i+1][1] = sumNearest(nhojCows[i], nhojCows[i+1]);
	}

}
