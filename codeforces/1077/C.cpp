#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

namespace utils {
	template<ull n, typename T>
	array<T, n> max_n(vector<T> &a) {
		array<T, n + 1> top;
		fill(top.begin(), top.end(), std::numeric_limits<T>::lowest());

		make_heap(top.begin(), top.end(), std::greater<T>());

		for (ull i = 0; i < a.size(); i++) {
			top[n] = a[i];
			push_heap(top.begin(), top.end(), std::greater<T>());
			pop_heap(top.begin(), top.end(), std::greater<T>());
		}

		sort_heap(top.begin(), prev(top.end()), std::greater<T>());

		array<T, n> out;
		for (ull i = 0; i < n; i++) {
			out[i] = top[i];
		}

		return out;
	}
}

int main() {
	ull n; cin >> n;
	vector<ull> a(n, 0);
	ull k = n;
	while (k--) cin >> a[k];

	ull sum = accumulate(a.begin(), a.end(), 0ull, plus<ull>());

	auto max = utils::max_n<2>(a);
	
	vector<ull> idxs;

	for (ull i = 0; i < a.size(); i++) {
		ull target = (a[i] == max[0] ? max[1] : max[0]);
		if (sum - a[i] - target == target) idxs.push_back(n - i);
	}

	cout << idxs.size() << endl;
	for (ull i = 0; i < idxs.size(); i++) cout << idxs[i] << " ";
	cout << endl;
}
