#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define SIZE 1000000000

bitset<SIZE> composite;

void sieve() {
	for (ull i = 2; i < SIZE; i++) {
		if (!composite[i]) {
			for (ull j = i * 2; j < SIZE; j += i) composite[j] = true;
		}
	}
}

ull nextPrime(ull n) {
	for (ull i = n + 1; i < SIZE; i++) {
		if (!composite[i]) return i;
	}
	return SIZE + 1;
}

int main(int argc, char** argv) {
	sieve();

	if (argc == 2) {
		cout << nextPrime(stoi(argv[1])) << endl; 
	}
	else if (argc == 3) {
		ull c = stoi(argv[2]);
		ull p = nextPrime(stoi(argv[1]));
		cout << p << " ";

		while (--c) {
			cout << p << " ";
			p = nextPrime(p);
		}
		cout << endl;
	}
}
