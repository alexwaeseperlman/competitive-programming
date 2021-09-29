#include <bits/stdc++.h>
using namespace std;
vector<string> words = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"ten",
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen",
	"twenty"
}, tens = {
	"",
	"ten",
	"twenty",
	"thirty",
	"forty",
	"fifty",
	"sixty",
	"seventy",
	"eighty",
	"ninety"
};

string toWords(int n) {
	string out = "";

	if (n < words.size()) return words[n];
	else if (n >= 1000) return "onethousand";
	else if (n >= 100) {
		return toWords(n / 100) + "hundred" + (n%100 ? ("and" + toWords(n%100)) : "");
	}
	else if (n >= 10) {
		return tens[n/10] + (n % 10 ? toWords(n%10):"");
	}
	return "onethousand";
}

int main() {
	int total = 0;
		
	while (false) {
		int s; cin >> s;
		cout << toWords(s) << endl;
	}

	for (int i = 1; i <= 1000; i++) {
		total += toWords(i).size();
	}
	cout << total << endl;
}
