#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int insert_point = lower_bound(intervals.begin(), intervals.end(), vector<int>{newInterval[0], newInterval[0]}) - intervals.begin();

        vector<vector<int>> ans;
        vector<int> cur = insert_point == 0 ? newInterval : intervals[0];
        for (int i = 0; i < intervals.size(); i++) {
        	vector<int> next;
        	if (i == insert_point) {
        		next = newInterval;
	        	if (next[0] <= cur[1]) {
	        		cur[1] = max(next[1], cur[1]);
	        	} else {
	        		ans.push_back(cur);
	        		cur = next;
	        	}
        	}
        	next = intervals[i];
        	if (next[0] <= cur[1]) {
        		cur[1] = max(next[1], cur[1]);
        	} else {
        		ans.push_back(cur);
        		cur = next;
        	}
        }
        if (insert_point == intervals.size()) {
        	if (newInterval[0] <= cur[1]) {
        		cur[1] = max(newInterval[1], cur[1]);
        	} else {
        		ans.push_back(cur);
        		cur = newInterval;
        	}
        }
        ans.push_back(cur);
        return ans;
    }
};

int main() {
	vector<vector<int>> intervals = {{1,5}};
	vector<int> newInterval = {2,7};

	Solution sol;
	vector<vector<int>> ans = sol.insert(intervals, newInterval);
	for (auto interval : ans) {
		cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
	}
}