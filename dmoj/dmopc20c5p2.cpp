#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	double n = N, m = M;

	vector<pair<int, int>> points;
	int y = 0;

	while (y < M) {
		double xIntercept1 = y * n / m, xIntercept2 = (y + 1) * n / m;

		int width = ceil(xIntercept2 - xIntercept1);

		for (int i = floor(xIntercept1); i < ceil(xIntercept2); i++) {
			points.emplace_back(i, y);
		}
		y++;
	}

	cout << points.size() << endl;
	for (int i = 0; i < points.size(); i++) {
		cout << points[i].first + 1 << " " << points[i].second + 1 << endl;
	}
}
