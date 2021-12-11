#include <bits/stdc++.h>
using namespace std;

pair<int, int> psum[20002][20002];

int main() {
	int N; cin >> N;
	vector<pair<int, int>> cows(N);
	for (int i = 0; i < N; i++) {
		cin >> cows[i].first >> cows[i].second;
		cows[i].first += 10000;
		cows[i].second += 10000;
		psum[cows[i].first+1][cows[i].second].first += cows[i].first;
		psum[cows[i].first][cows[i].second+1].first += cows[i].second;
	}

	for (int i = 1; i <= 20001; i++) {
		for (int j = 1; j <= 20001; j++) {
			psum[i][j].first += psum[i-1][j].first;
			psum[i][j].second += psum[i][j-1].second;
		}
	}

	
}
