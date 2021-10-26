#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v(n+1);
	vector<bool> decreased;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		decreased.push_back(v[i] <= v[i-1]);
	}
	decreased.push_back(false);

	// Remove non-increasing regions that are all the same value
	int s = 0;
	for (int i = 1; i < n+1; i++) {
		if (decreased[i] && !decreased[i-1]) s = i;
		if (!decreased[i] && decreased[i-1]) {
			if (v[i] == v[s]) {
				for (int j = s; j <= i; j++) decreased[j] = false;
			}
		}

	}

	int regions = 0;
	int start = 0, end = 0;
	for (int i = 1; i <= n; i++) {
		if (decreased[i] && !decreased[i-1]) {
			regions++;
			start = i;
		}
		if (!decreased[i] && decreased[i-1]) {
			end = i;
		}
	}
	if (regions == 0) {
		cout << 1 << " " << 1 << endl;
	}
	else if (regions == 1 && (start == 0 || v[start-1] <= v[end]) && (end + 1 >= v.size() || v[start] <= v[end+1])) {
		cout << start << " " << end;
	}
	else {
		cout << "impossible" << endl;
	}

}
