#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct vecComp {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
		return a.first < b.first;
	}
};

struct queueComp {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
		return a.first > b.first;
	}
};

class Solution {
public:
	vector<int> findRightInterval(vector<vector<int> > &intervals) {
		vector<pair<int, int> > list;
		priority_queue<pair<int, int>, vector<pair<int, int> >, queueComp> pq;
		vector<int> ans(intervals.size(), -1);

		for (int i = 0; i < intervals.size(); ++i) {
			list.push_back(make_pair(intervals[i][1], i));	// (end point, index)
			pq.push(make_pair(intervals[i][0], i));			// (start point, index)
		}
		sort(list.begin(), list.end(), vecComp());

		for (int i = 0; i < list.size(); ++i) {
			int end_point = list[i].first;
			while (!pq.empty() && pq.top().first < end_point) {
				pq.pop();
			}
			if (!pq.empty()) {
				ans[list[i].second] = pq.top().second;
			}
		}
		return ans;
	}
};

int main() {
	int array1[] = {3, 4};
	int array2[] = {2, 3};
	int array3[] = {1, 2};
	vector<vector<int> > intervals;
	intervals.push_back(vector<int>(array1, array1 + 2));
	intervals.push_back(vector<int>(array2, array2 + 2));
	intervals.push_back(vector<int>(array3, array3 + 2));

	Solution sol;
	vector<int> ans = sol.findRightInterval(intervals);

	for (int i = 0; i < intervals.size(); ++i) {
		cout << ans[i] << endl;
	}
}