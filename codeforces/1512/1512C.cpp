#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
	for (int i = 0; i <= s.size() / 2 + 1; i++) {
		if (s[s.size() - 1 - i] != s[i]) return false;
	}
	return true;
}

void solve() {
	int amounts[2];
	cin >> amounts[0] >> amounts[1];

	string s;
	cin >> s;

	string output = "";
	int counts[2] = { amounts[0], amounts[1] };
	for (int i = 0; i < s.size(); i++) {
		output += s[i] == '?' ? s[s.size() - 1 - i] : s[i];

		if (output[i] != '?') counts[output[i] - '0']--;
	}


	for (int i = 0; i < s.size(); i++) {
		if (output[i] == '?') {
			bool one = counts[0] < (1 + (output.size() - 1 - i != i));

			output[i] = '0' + one;
			counts[one]--;

			if (output.size() - 1 - i != i) {
				output[output.size() - 1 - i] = output[i];
				counts[one]--;
			}
		}
	}


	if (counts[0] != 0 || counts[1] != 0 || !isPalindrome(output)) {
		cout << "-1" << endl;
		return;
	}

	cout << output << endl;

}	

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) solve();

}
