#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<unordered_map<int, unordered_map<int, int>>> eqRows;
vector<unordered_map<int, unordered_map<int, int>>> eqCols;
bool ugly(int x1, int y1, int x2, int y2) {
	int width = x2 - x1 + 1, height = y2 - y1 + 1;
	int maxHeight = eqRows[x1][y1][x2], maxWidth = eqCols[y1][x1][y2];

	//cout << x1 << "," << y1 << " - " << x2 << "," << y2 << " has dimensions " << width << "," << height << " and is equal with dimensions " << maxWidth << "," << maxHeight << ", adding " << (width <= maxWidth && height <= maxHeight) << endl;

	return width <= maxWidth && height <= maxHeight;
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<bool>> grid(M, vector<bool>(N, false));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			char c;
			cin >> c;
			grid[i][j] = c == 'Y';
		}
	}

	eqCols.resize(N);
	eqRows.resize(M);

	for (int i = 0; i < M; i++) {
		for (int j = i+1; j < M; j++) {
			int c = 0;
			for (int k = N-1; k >= 0; k--) {
				if (grid[i][k] == grid[j][k]) eqRows[i][k][j] = max(++c, eqRows[i][k][j]);
				else c = 0;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			int c = 0;
			for (int k = M-1; k >= 0; k--) {
				if (grid[k][i] == grid[k][j]) eqCols[i][k][j] = max(++c, eqCols[i][k][j]);
				else c = 0;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < M-1; i++) {
		for (int j = 0; j < N-1; j++) {
			for (int k = i + 1; k < M; k++) {
				for (int l = j + 1; l < N; l++) {
					count += ugly(i, j, k, l);
				}
			}
		}
	}

	cout << count << endl;
}
