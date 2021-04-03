#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

struct changeEntry {
	long long position;
	long long change;
};

struct person {
	long long position;
	long long speed;
	long long hearing;
};

struct byPosition {
	bool operator() (changeEntry const& a, changeEntry const& b) const {
		return a.position < b.position;
	}
};

int main() {
	int N;
	std::cin >> N;

	std::vector<changeEntry> changes;
	std::vector<person> people;
	long long changeRate = 0;

	for (long long i = 0; i < N; i++) {
		long long position, speed, hearing;
		std::cin >> position >> speed >> hearing;

		changes.push_back((changeEntry){ position - hearing, speed });
		changes.push_back((changeEntry){ position + hearing, speed });
		changeRate -= speed;

		people.push_back((person){position, speed, hearing});
	}
	std::sort(changes.begin(), changes.end(), byPosition());

	long long sum = 0;
	long long previousPosition = changes[0].position;
	long long position = changes[N * 2 - 1].position;
	for (long long i = 0; i < N * 2; i++) {
		sum += changeRate * (changes[i].position - previousPosition);
		previousPosition = changes[i].position;
		changeRate += changes[i].change;
		if (changeRate > 0) {
			position = previousPosition;
			break;
		}
	}

	long long time = 0;
	for (long long i = 0; i < N; i++) {
		time += std::max<long long>(people[i].speed * (abs(people[i].position - position) - people[i].hearing), 0l);
	}
	std::cout << time << std::endl;

	return 0;
}
