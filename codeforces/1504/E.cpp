#include <iostream>
#include <algorithm>
#include <bitset>
#include <limits>
#include <queue>
#include <set>

#define MAX_CITIES (100001)

using namespace std;

struct city {
	long long first, second;
};

bool operator<(const city& l, const city& r) {
	return l.first < r.first;
}

using ll = long long;

bitset<MAX_CITIES> visited;
int path[MAX_CITIES];
city cities[MAX_CITIES];
ll dp[MAX_CITIES];

// Djikstra's algorithm can be used to find the shortest path to the most beautiful city.
// Once there we can travel to less beautiful cities without wasting computations because we are guaranteed
// to only pay the priceFloor
ll djikstra(int start, int end, int len) {
	// Djikstra's algorithm works from the nearest city at each step so a priority queue can be used to find these
	// This pair stores data in the following order: 
	// 		distance - a negative integer because priority queues will return the largest value unless given a custom comparator
	// 		index - the index of the city in all of the arrays
	priority_queue<pair<ll, int>> heap;

	dp[start] = 0;
	heap.emplace(0, start);

	while (!heap.empty()) {
		// Start at the closest city
		auto [dist, idx] = heap.top();
		dist = -dist;
		// If the closest unvisited city is the target then this is the answer
		if (idx == end) return dist;
		heap.pop();
		// If the city was visited by another node and it found a better distance there is no reason to try paths from here
		if (dp[idx] < dist) continue;

		for (int i = 0; i < len; ++i) {
			if (i == idx || cities[i].first < cities[idx].first) continue;
			// The distance from city idx to city i as defined in the problem explanation is the max of the difference in beauty and the price floor of city idx
			ll currentDist = max(cities[i].first - cities[idx].first, cities[idx].second) + dp[idx];

			if (currentDist < dp[i]) {
				dp[i] = currentDist;
				heap.emplace(-currentDist, i);
				// Store that getting to point i from point idx is the most efficient way 
				path[i] = idx;
			}

		}
	}
	return -1;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		ll b, f;
		cin >> b >> f;
		cities[i] = city{b, f};
		dp[i] = numeric_limits<int>::max();
	}

	int bestIdx = max_element(cities, cities + n) - cities;

	std::cout << "starting djikstra" << endl;
	ll dist = djikstra(0, bestIdx, n);

	cout << "Done djikstra" << endl;

	for (; bestIdx; bestIdx = path[bestIdx]) {
		visited[bestIdx] = true;
	}
	visited[0] = true;

	priority_queue<city> remaining;
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) remaining.push(cities[i]);
	}

	city last = remaining.top();
	while (remaining.size()) {
		dist += remaining.top().second;
		last = remaining.top();
		remaining.pop();
	}
	cout << dist + max(cities[0].first - last.first, last.second) << endl;
}
