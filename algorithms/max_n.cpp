namespace utils {
	using namespace std;
	using ull = unsigned long long;
	using ll = long long;
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
