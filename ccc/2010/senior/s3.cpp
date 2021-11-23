#include <bits/stdc++.h>
using namespace std;

int k, h;
vector<int> houses;
int testLen(int l) {
	for (int i = 0; i < h; i++) {
		int pos = houses[i], end = 0, count = 1, j;
		for (j = 1; j < h; j++) {
			int step = (1000000+houses[(i+j)%h]-houses[(i+j-1)%h])%1000000;
			end += step;
			if (end > 2*l) {
				pos = houses[(i+j)%h];
				end = 0;
				count++;
			}
		}
		if (count <= k) return true;
	}
	return false;
}

int main() {
	cin >> h;
	houses.resize(h);
	for (int i = 0; i < h; i++) cin >> houses[i];
	sort(houses.begin(), houses.end());

	cin >> k;

	int lb = 0, ub = 1000001;
	while (lb < ub) {
		int m = lb + (ub-lb)/2;

		if (testLen(m)) ub = m;
		else lb = m+1;
	}

	cout << lb << endl;
}
