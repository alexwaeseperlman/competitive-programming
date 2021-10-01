#include <bits/stdc++.h>
using namespace std;

const int startYear = 1901, endYear = 2000, startDay = 0;

vector<int> monthLen{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leapYear(int y) {
	return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
}

int main() {
	int day = startDay, total = 0;
	for (int i = startYear; i <= endYear; i++) {
		for (int month = 0; month < 12; month++) {
			total += (day == 0);
			day += monthLen[month];
			if (leapYear(i) && month == 1) day++;
			day %= 7;
		}
	}
	cout << total << endl;
	
}
