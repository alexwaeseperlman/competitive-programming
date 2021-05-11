#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		vector<int> arr;
		for (int j = 0; j < n; j++) {
			int k;
			cin >> k;
			arr.push_back(k);
		}

		for (int j = 1; j < n - 1; j++) {
			if (arr[j] != arr[j - 1]) {
				if (arr[j + 1] == arr[j]) cout << j << endl;
				else cout << j + 1 << endl;
				goto end;
			}
		}
		cout << n << endl;
end:;
	}
	
}
