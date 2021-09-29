#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;


int main() {
	unordered_map<bitset<6>, bitset<6>> connections;

	for (int i = 0; i < 64; i++) {
		bitset<6> b = static_cast<bitset<6>>(i);
		bitset<6> c;
		for (int j = 0; j < 5; j++) c[j] = b[j+1];
		c[5] = (b[1] && b[2]) != b[0];

		connections[c] = b;
	}

	vector<vector<bitset<6>>> cycles;
	while (connections.size()) {
		bitset<6> i = connections.begin()->first;
		vector<bitset<6>> cycle;

		while (connections.count(i)) {
			bitset<6> n = connections[i];
			connections.erase(i);
			cycle.push_back(i);
			cout << i << " ";
			i = n;
		}
		cout << i;
		cycle.push_back(i);
		cycles.push_back(cycle);
		cout << endl;
	}

	vector<ull> fib;
	fib.push_back(0);
	fib.push_back(1);
	fib.push_back(1);
	for (ull i = 3; i < 10000; i++) {
		fib.push_back(fib[i-1] + fib[i-2]);
	}

	ull prod = 1;
	for (ull i = 0; i < cycles.size(); i++) {
		ull a = fib[cycles[i].size()-2] + fib[cycles[i].size()];
		prod *= a;
	}
	cout << prod << endl;

}
