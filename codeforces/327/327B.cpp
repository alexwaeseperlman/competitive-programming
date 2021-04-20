#include <iostream>
#include <bitset>

using namespace std;

bitset<10000001> primeSieve;

int main() {
	int n, printed;
	cin >> n;

	for (int i = 2; printed < n; i++) {
		if (!primeSieve[i]) {
			for (int j = i * 2; j < 2000001; j += i) {
				primeSieve[j] = true;
			}

			printed++;
			cout << i << " ";
		}
	}
	cout << endl;

	return 0;
}
