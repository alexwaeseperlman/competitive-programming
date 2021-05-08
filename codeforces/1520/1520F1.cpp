#include <iostream>

using namespace std;

int query(int lb, int ub) {
	cout << "? " << lb << " " << ub << endl;
	cout.flush();
	int sum;
	cin >> sum;
	return sum;
}

void solve(int n) {
	int k;
	cin >> k;
	int lb = 1, ub = n;
	int zeros;

	int sum = query(1, n);
	zeros = n - sum;

	while (ub - lb >= 1) {
		int i = (ub + lb) / 2;
		int sum = query(1, i);
		int targetSum = i;
		zeros = targetSum - sum;
		
		if (zeros < k) lb = i + 1;
		else ub = i;
	}

	cout << "! " << lb << endl;
}

int main() {
	int n, t;
	cin >> n >> t;

	while (t--) solve(n);

}
