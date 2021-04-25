#include <bits/stdc++.h>
#pragma GCC optimize("O3")

int log2i[1001];

// map of ranges to the minimum value in a square
int mins[10][10][1001][1001];
int w, h;

// assume x1 < x2 and y1 < y2
int minquery(int x1, int x2, int y1, int y2, int xmax=10000000, int ymax=10000000) {
	// get the size of the query
	int xindex = std::min(log2i[x2-x1+1], xmax), yindex = std::min(log2i[y2-y1+1], ymax);
	int sizex = 1 << xindex, sizey = 1 << yindex;

	int result = INT32_MAX;

	// This is a manually unrolled version of the following loop
	/*
	  for (int x = x1; x <= x2 && x < xiter; x += sizex) {
		  for (int y = y1; y <= y2 && x < yiter; y += sizey) {
			  int sectionmin = ranges[xindex][yindex][min(x, x2 - sizex + 1)][min(y, y2 - sizey + 1)];
			  if (sectionmin < result) result = sectionmin;
		  }
	  }
	 */
	{

		int nx = std::min(x1 + sizex, x2 - sizex + 1), ny = std::min(y1 + sizey, y2 - sizey + 1);
		if (mins[xindex][yindex][x1][y1] < result) result = mins[xindex][yindex][x1][y1];
		
		if (x1 + sizex < w && mins[xindex][yindex][nx][y1] < result) 
			result = mins[xindex][yindex][nx][y1];

		if (y1 + sizey < h && mins[xindex][yindex][x1][ny] < result) 
			result = mins[xindex][yindex][x1][ny];

		if (x1 + sizex < w && y1 + sizey < h && mins[xindex][yindex][nx][ny] < result)
			result = mins[xindex][yindex][nx][ny];
	}
	return result;
}

void init(int xlayers, int ylayers) {
	// what the fuck
	for (int i = 0; i < xlayers; i++) {
		for (int j = 0; j < ylayers; j++) {
			if (i == 0 && j == 0) continue;
			int sizex = 1 << i, sizey = 1 << j;
			//cout << sizex << " " << sizey << endl;
			for (int x = 0; x < w; x++) {
				for (int y = 0; y < h; y++) {
					mins[i][j][x][y] = (minquery(x, x + sizex - 1, y, y + sizey - 1, j == 0 ? i - 1 : i, j == 0 ? j : j - 1));
				}
			}
		}
	}
}

void init(std::vector<std::vector<int>> arr) {
	w = arr.size(); h = arr[0].size();
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			mins[0][0][i][j] = arr[i][j];
		}
	}
	log2i[0] = 0;
	for (int i = 0; i < 1001; i++) {
		log2i[i] = (int)log2(i);
	}
	init(log2i[arr.size()] + 1, log2i[arr[0].size()] + 1);
}

int query(int a, int b, int c, int d) {
	return minquery(a, b, c, d);
}

int main() {
	using namespace std;
	vector<vector<int>> data;
	for (int i = 0; i < 1000; i++) {
		data.push_back(vector<int>());
		for (int j = 0; j < 1000; j++) {
			data[i].push_back(-(i + j + 1));
		}
	}

	cout << "indexing" << endl;
	init(data);
	cout << "done" << endl;
	
	int sum = 0;
	for (int i = 0; i < 10000000; i++) {
		int x1 = rand() % 1000, y1 = rand() % 1000;
		int x2 = x1 + rand() % (1000 - x1), y2 = y1 + rand() % (1000 - y1);
		sum += query(x1, x2, y1, y2);
	}
	cout << sum << endl;
}
