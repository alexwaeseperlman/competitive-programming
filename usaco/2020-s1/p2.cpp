#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int psum[2503][2503];
bool point[2503][2503];

int countRange(int x1, int y1, int x2, int y2) {
	return psum[x2+1][y2+1] - psum[x1][y2+1] - psum[x2+1][y1] + psum[x1][y1];
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N; cin >> N;
	vector<pair<int, int>> points(N);

	for (int i = 0; i < N; i++) {
		cin >> points[i].first >> points[i].second;
	}
	sort(points.begin(), points.end());
	for (int i = 0; i < N; i++) {
		points[i].first = i;
		points[i] = {points[i].second, points[i].first};
	}
	sort(points.begin(), points.end());
	for (int i = 0; i < N; i++) {
		points[i].first = i;
		points[i] = {points[i].second, points[i].first};
	}
	sort(points.begin(), points.end());

	for (auto p : points) {
		point[p.first][p.second] = true;
	}
	for (int i = 1; i <= N+2; i++) {
		for (int j = 1; j <= N+2; j++) {
			psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + point[i-1][j-1];
		}
	}

	long long total = 1;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			int left = countRange(min(points[i].first, points[j].first), 0, max(points[i].first, points[j].first), min(points[i].second, points[j].second)), 
				right = countRange(min(points[i].first, points[j].first), max(points[i].second, points[j].second), max(points[i].first, points[j].first), N+1);
			total += left*right;
		}
	}

	cout << total << endl;
}
