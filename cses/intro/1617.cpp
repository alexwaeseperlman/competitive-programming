#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int out = 1;
	while (n--) {
		out = (2*out)%1000000007;
	}
	cout << out << endl;
}
