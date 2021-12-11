#include <bits/stdc++.h>
using namespace std;

map<int, int> counts[2];
int main() {
	int N, B; cin >> N >> B;
	vector<int> A(N), d(N+1);
	for (int i = 0; i < N; i++) cin >> A[i];

	for (int i = 1; i <= N; i++) {
		d[i] = d[i-1] - (A[i-1] > B) + (A[i-1] < B);
	}

	int total = 0;
	for (int s : {0, 1}) {
		for (int i = s; i <= N; i += 2) {
			counts[s][d[i]]++;
		}

	}
	for (auto [i, j] : counts[0]) {
		total += j * counts[1][i];
	}

	cout << total << endl;
}
