#include <bits/stdc++.h>

using namespace std;

map<int, int> primeFactors(int n) {
	map<int, int> out;
	int i = 1;
	while (n > 1) {
		i++;
		if (n%i == 0) {
			out[i]++;
			n/=i;
			i = 1;
		}
	}
	return out;
}

int divisorSum(int n) {
	auto factors = primeFactors(n);

	int prod = 1;
	for (auto [factor, count] : factors) {
		prod *= (pow(factor, count+1)-1)/(factor-1);
	}
	prod -= n;
	return prod;
}

bitset<30000> abundant;
vector<int> abundantNums;

int main() {
	for (int i = 2; i < 30000; i++) {
		abundant[i] = divisorSum(i) > i;
		if (abundant[i]) abundantNums.push_back(i);
	}

	int total = 0;
	for (int i = 0; i < 30000; i++) {
		bool possible = false;
		for (int a : abundantNums) {
			if (a > i) break;
			if (abundant[i-a]) {
				possible=true;
				break;
			}
		}
		if (!possible) total += i;
	}
	cout << total << endl;

}
