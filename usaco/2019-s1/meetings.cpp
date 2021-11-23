#include <iostream>
#include <fstream>
#include <vector>

using ll = long long;
using namespace std;

struct cow {
	bool right;
	ll pos, weight;
};
int main() {
	ll N, L; cin >> N >> L;

	vector<cow> cows(N);

	for (int i = 0; i < N; i++) {
		ll w, x, d; cin >> w >> x >> d;
		cows[i].right = d == 1;
		cows[i].pos = x;
		cows[i].weight = w;
	}

}
