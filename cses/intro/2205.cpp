#include <bits/stdc++.h>
using namespace std;

vector<string> step(vector<string> &ss) {
	vector<string> out;
	bool last = 0;
	for (string s : ss) {
		out.push_back(s + (last?'1':'0'));
		out.push_back(s + (last?'0':'1'));
		last = !last;
	}
	return out;
}

int main() {
	int n; cin >> n;
	vector<string> a(1);
	for (int i = 0; i < n; i++) a = step(a);
	for (string s : a) cout << s << endl;


}
