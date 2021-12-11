#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct cow {
	ll a, t, seniority;
	bool operator<(const cow &rhs) const {
		return seniority < rhs.seniority;
	}
};

int main() {
	ifstream in;
	ofstream out;
	in.open("convention2.in");
	out.open("convention2.out");
	ll N; in >> N;
	vector<cow> cows(N);
	for (ll i = 0; i < N; i++) {
		in >> cows[i].a >> cows[i].t;
		cows[i].seniority = -i;
	}

	sort(cows.begin(), cows.end(), [&](const cow &lhs, const cow &rhs) {
		return lhs.a < rhs.a;
	});

	priority_queue<cow> waiting;
	waiting.push(cows[0]);
	ll m = 0, i = 1, tl = cows[0].t, t = cows[0].a;
	while (waiting.size()) {
		cow top = waiting.top();
		waiting.pop();
		m = max(t - top.a, m);
		t += top.t;

		while (i < N && cows[i].a <= t) {
			waiting.push(cows[i]);
			i++;
		}
		if (waiting.size() == 0 && i < N) {
			int j = i;
			for (; j < N && cows[j].a == cows[i].a; j++) {
				waiting.push(cows[j]);
			}
			t = cows[i].a;
			i = j;
		}
	}
	
	out << m << endl;
	out.close();
	in.close();
}
