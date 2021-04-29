#include <iostream>
#include <set>
using namespace std;

set<int> freeGates;

int main() {
	int G, P;
	cin >> G >> P;

	for (int i = 0; i < G + 1; i++) {
		freeGates.insert(i);
	}

	int added = 0;
	for (int i = 0; i < P; i++) {
		int p;
		cin >> p;

		auto lower = prev(freeGates.upper_bound(p));
		if (lower == freeGates.begin()) break;
		
		added++;
		freeGates.erase(lower);
	}
	cout << added << endl;
}
