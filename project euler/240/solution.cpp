#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const int TOP=10, TOTAL=20, TARGET=70, SIDES=12;
//const int TOP=3, TOTAL=5, TARGET=15, SIDES=6;


vector<map<ull, ull>> waysToSumMemo[TARGET+1][TOTAL+1][SIDES+1][SIDES+1];
vector<map<ull, ull>> waysToSumTo(ull n, ull k, ull high, ull low=1) {
	if (n < k*low || n > k*high) return vector<map<ull, ull>>(0);
	if (k == 1) return { map<ull, ull>{ {n, 1} } };
	if (waysToSumMemo[n][k][high][low].size()) return waysToSumMemo[n][k][high][low];


	vector<map<ull, ull>> out;
	for (ull i = max(low, (n+k-1)/k); i <= high && n-i-(k-1)*low+1 >= 0; i++) {
		vector<map<ull, ull>> a = waysToSumTo(n-i, k-1, i, low);
		if (a.size() == 0) break;
		for (auto j : a) {
			j[i]++;
			out.push_back(j);
		}
	}

	waysToSumMemo[n][k][high][low] = out;
	return out;
}

ull choose(ull n, ull k) {
	ull out = 1, j=1;
	for (ull i = k+1; i <= n; i++) {
		out *= i;
		out /= j++;
	}

	return out;
}

ull p(ull n, ull k) {
	ull out = 1;
	for (int i = 0; i < k; i++) out *= n;

	return out;
}

int main() {
	auto ways = waysToSumTo(TARGET, TOP, SIDES, 1);
	ull total = 0;

	for (auto top10 : ways) {
		ull spaces = TOTAL;
		
		ull min = 0, amt = 1;
		for (auto [roll, num] : top10) {
			if (!min) {
				min = roll;
				continue;
			}
			amt *= choose(spaces, num);
			spaces -= num;
		}

		for (int i = 0; i <= TOTAL-TOP; i++) {
			total += amt * choose(spaces, top10[min]+i) * p(min-1, spaces-top10[min]-i);
		}
	}
	cout << total << endl;
}
