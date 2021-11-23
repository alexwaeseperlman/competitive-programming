#include <bits/stdc++.h>
using namespace std;

bool num(string &s) {
	for (char c : s) if (c < '0' || c > '9') return false;
	return true;
}
int main() {
	string x, y; cin >> x >> y;
	if (num(x) && num(y)) cout << (stoi(x) - stoi(y)) << endl;
	else cout << "NaN" << endl;


}
