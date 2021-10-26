#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main() {
	int t; cin >> t;
	while (t--) {
		ull a, b, c; cin >> a >> b >> c;

		ull x=0, y=0;
		x += 3*(c/2);
		y += 3*(c-c/2);

		x += 2*(b-b/2);
		y += 2*(b/2);
		
		cout << (x-y+a)%2 << endl;
	}
}
