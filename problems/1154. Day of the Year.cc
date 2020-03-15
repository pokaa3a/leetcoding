#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	int dayOfYear(string date) {
		vector<int> month(12, 31);
		month[2 - 1] = 28;
		month[4 - 1] = 30;
		month[6 - 1] = 30;
		month[9 - 1] = 30;
		month[11 - 1] = 30;

		int y = stoi(date.substr(0, 4));
		if (isLeap(y)) month[2 - 1] = 29;
		int m = stoi(date.substr(5, 2));
		int d = stoi(date.substr(8, 2));
		int days = 0;
		for (int i = 1; i < m; ++i) {
			days += month[i - 1];
		}
		days += d;
		return days;
	}
private:
	bool isLeap(int y) {
		if (( y % 4 == 0 && y % 100 != 0) || (y % 400 == 0 && y % 3200 != 0))
			return true;
		else
			return false;
	}
};

int main() {
	string date = "2004-03-01";
	Solution sol;
	cout << sol.dayOfYear(date) << endl;
}