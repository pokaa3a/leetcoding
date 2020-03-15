#include <iostream>
#include <vector>
using namespace std;

struct comp {
	bool operator() (const vector<int> &a, const vector<int> &b) {
		if (a[0] < b[0]) {
			return true;
		} else if (a[0] == b[0]) {
			return a[1] < b[1];
		}
		return false;
	}
};

class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int> > &intervals) {
		if (!intervals.size()) return 0;
		int remove = 0;

		// Sort input intervals
		sort(intervals.begin(), intervals.end(), comp());

		// Walk through intervals and select removed items
		vector<int> current = intervals[0];
		for (int i = 1; i < intervals.size(); ++i) {
			vector<int> next = intervals[i];

			// Check if next item and current item have overlap
			if (current[1] > next[0]) {
				remove++;
				if (current[1] < next[1]) {
					continue;
				}
			}
			current = next;
		}
		return remove;
	}
};

int main() { 
	vector<vector<int> > intervals;
	int array1[] = {1, 2};
	intervals.push_back(vector<int>(array1, array1 + 2));
	int array2[] = {1, 2};
	intervals.push_back(vector<int>(array2, array2 + 2));
	int array3[] = {1, 2};
	intervals.push_back(vector<int>(array3, array3 + 2));
	// int array4[] = {1, 3};
	// intervals.push_back(vector<int>(array4, array4 + 2));

	Solution sol;
	cout << sol.eraseOverlapIntervals(intervals) << endl;
}