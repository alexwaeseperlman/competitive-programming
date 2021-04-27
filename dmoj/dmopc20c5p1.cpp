#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string S, T;
	cin >> S >> T;

	int i = 0;
	for (; i < min(S.size(), T.size()); i++) {
		if (S[i] != T[i]) break;
	}

	cout << T.size() - i + S.size() - i << endl;
}
