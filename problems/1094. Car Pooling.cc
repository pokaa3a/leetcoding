#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool carPooling(vector<vector<int> >& trips, int capacity) {
		vector<int> route(1000 + 1, 0);
		for (int i = 0; i < trips.size(); ++i) {
			route[trips[i][1]] += trips[i][0];
			route[trips[i][2]] -= trips[i][0];
		}

		int current = 0;
		for (int i = 0; i < 1000 + 1; ++i) {
			current += route[i];
			if (current > capacity) return false;
		}
		return true;
	}
};

int main() {
	int trip1[] = {3, 2, 7};
	int trip2[] = {3, 7, 9};
	int trip3[] = {8, 3, 9};

	vector<vector<int> > trips;
	trips.push_back(vector<int>(trip1, trip1 + 3));
	trips.push_back(vector<int>(trip2, trip2 + 3));

	int capacity = 11;

	Solution sol;
	cout << sol.carPooling(trips, capacity) << endl;
}