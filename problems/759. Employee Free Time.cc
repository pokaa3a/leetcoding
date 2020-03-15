#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <cmath>
#include <numeric>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void traverse(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	traverse(root->left);
	traverse(root->right);
}

/* Solution */
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval> > schedule) {
    	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    	vector<Interval> ans;

    	for (int i = 0; i < schedule.size(); ++i) {
    		for (int j = 0; j < schedule[i].size(); ++j) {
    			pq.push(make_pair(schedule[i][j].start, schedule[i][j].end));
    		}
    	}
    	pair<int, int> p = pq.top(); pq.pop();
    	int prev = p.second;
    	while (!pq.empty()) {
    		p = pq.top(); pq.pop();
    		if (prev < p.first) {
    			ans.push_back(Interval(prev, p.first));
    		}
    		prev = max(prev, p.second);
    	}
    	return ans;
    }
};


int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

	vector<vector<Interval> > schedule(3, vector<Interval>());
	schedule[0].push_back(Interval(1,2));
	schedule[0].push_back(Interval(5,6));
	schedule[1].push_back(Interval(1,3));
	schedule[2].push_back(Interval(4,10));

	vector<Interval> ans = sol.employeeFreeTime(schedule);
	for (int i = 0; i < ans.size(); ++i) cout << ans[i].start << ", " << ans[i].end << endl;


	/* [2-D vector] */
	// const int rows = 1;
	// const int cols = 1;
	// int arr[rows][cols] = {{1}};
	// vector<vector<int> > grid;
	// for (int r = 0; r < rows; ++r) {
	// 	grid.push_back(vector<int>(arr[r], arr[r] + cols));
	// }

	/* [String] */
	// string str = "";

}