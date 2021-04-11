#include <iostream>
#include <string>

using namespace std;

string reverseBrackets(string brackets, string bits) {
	string out = "";
	for (int i = 0; i < brackets.size(); i++) {
		if (bits[i] == '0') out += brackets[i] == ')' ? '(' : ')';
		else out += brackets[i];
	}
	return out;
}

bool validBrackets(string brackets) {
	int acc = 0;
	for (int i = 0; i < brackets.size(); i++) {
		if (brackets[i] == '(') acc++;
		else acc--;
		if (acc < 0) return false;
	}
	if (acc > 0) return false;
	return true;
}

void solve() {
	int n;
	cin >> n;

	string bits;
	cin >> bits;
	int ones = 0;
	for (int i = 0; i < bits.size(); i++) {
		if (bits[i] == '1') ones++;
	}
	if (ones % 2 == 1 || bits.size() % 2 == 1) {
		cout << "NO" << endl;
		return;
	}

	int oAdded = 0;
	char nextBracket = '(';

	string out = "";
	
	for (int i = 0; i < n; i++) {
		bool eq = bits[i] == '1';
		if (eq) {
			if (oAdded < ones / 2) out += '(';
			else out += ')';
			oAdded++;
			continue;
		}
		out += nextBracket;
		nextBracket = nextBracket == '(' ? ')' : '(';
	}

	string opposite = reverseBrackets(out, bits);
	if (validBrackets(opposite) && validBrackets(out)) {
		cout << "YES" << endl;
		cout << out << endl;
		cout << opposite << endl;
		return;
	}
	cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) solve();
}
