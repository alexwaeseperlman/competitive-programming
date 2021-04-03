#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	string s;
	for (int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		cin >> s;
		
		int count = 1;
		for (int j = s.find('*', 0) + 1; j < n; j++) {
			for (int l = min(j + k - 1, n - 1); l >= j && l >= 0; l--) {
				if (s[l] == '*') {
					count++;
					j = l;
					break;
				}
			}
		}
		cout << count << endl;
	}
}
