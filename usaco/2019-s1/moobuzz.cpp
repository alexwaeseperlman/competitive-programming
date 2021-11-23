#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream s;
	s.open("moobuzz.in");
	int N = 0; s >> N;
	s.close();

	auto amt = [&](long long n) {
		return n - n/3 - n/5 + n/15;
	};

	long long ub = 5000000000, lb = 0;
	while (lb<ub) {
		long long m = (ub+lb)/2;

		if (amt(m) > N) ub = m;
		else lb = m+1;
	}

	for (long long i = -5; i <= 5; i++) {
		if (amt(i+lb) == N) {
			lb += i;
			break;
		}
	}

	ofstream o;
	o.open("moobuzz.out");
	o << lb << endl;
	o.close();
}
