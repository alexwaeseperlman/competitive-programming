#include <bits/stdc++.h>
using namespace std;

int inversions(vector<int> &a) {
	int inv = 0;
	for (int i = 0; i < a.size()-1; i++) {
		for (int j = i+1; j < a.size(); j++) {
			if (a[j] < a[i]) inv++;
		}
	}
	return inv;
}

int main() {
	vector<int> p;
	for (int i = 1; i <= 6; i++) {
		p.push_back(i);
	}
	vector<int> a;
	for (int i = 1; i <= 6; i++) {
		a.push_back(i);
	}
	for (int i = 6; i >= 1; i--) a.push_back(i);

	int mInv = 100000;
	do {
		vector<int> b;
		for (int i = 0; i < a.size(); i++) {
			b.push_back(p[a[i]-1]);
		}
		if (inversions(b) <= mInv) {
			mInv = inversions(b);
			cout << mInv << endl;
			for (int i : p) cout << i << " " ;
			cout << endl;
		}

	} while (next_permutation(p.begin(), p.end()));


}
