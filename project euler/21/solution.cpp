#include <bits/stdc++.h>

using namespace std;

const int N = 10000;
int divisorSums[N*5];

vector<int> primeFactors(int n) {
	vector<int> out;
	int i = 1;
	while (n > 1) {
		i++;
		if (n % i == 0) {
			out.push_back(i);
			n /= i;
			i = 1;
		}
	}

	return out;
}

int divisorSum(int n) {
	auto p = primeFactors(n);

	map<int, int> sums;
	for (int i : p) {
		cout << i << " ";
		sums[i] = max(sums[i],1) * i + 1;
	}
	cout << endl;

	int total = 1;
	for (auto [i, j] : sums) {
		total *= j;
	}

	return total;
}

int main() {
	divisorSums[1] = 1;
	for (int i = 2; i < N*5; i++) {
		divisorSums[i] = divisorSum(i) - i;
		cout << i << " "<< divisorSums[i] << endl;
	}

	int s = 0;
	for (int i = 0; i < N; i++) {
		if (divisorSums[divisorSums[i]] == i && i != divisorSums[i]) {
			s += i;
		}
	}
	cout << divisorSums[220] << endl;
	
	cout << s << endl;
}

