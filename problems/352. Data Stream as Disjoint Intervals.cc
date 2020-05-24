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
const int MOD = 1000000007;
class SummaryRanges {
public:
    set<pair<int, int>> intervals;
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if (intervals.empty()) {
            intervals.insert(make_pair(val, val));
            return;
        }
        
        auto it = intervals.lower_bound(make_pair(val, val));
        if (it == intervals.begin()) {
            if (it->first <= val + 1) {
                pair<int, int> new_interval = {val, it->second};
                intervals.erase(it);
                intervals.insert(new_interval);
            } else {
                intervals.insert(make_pair(val, val));
            }
        } else if (it == intervals.end()) {
            it = prev(it);
            if (it->second >= val - 1) {
                pair<int, int> new_interval = {it->first, max(it->second, val)};
                intervals.erase(it);
                intervals.insert(new_interval);
            } else {
                intervals.insert(make_pair(val, val));
            }
        } else {
            auto prev_it = prev(it);
            if (val <= prev_it->second || val == it->first) {
                // do nothing
            } else if (val == prev_it->second + 1 && val == it->first - 1) {
                pair<int, int> new_interval = {prev_it->first, it->second};
                intervals.erase(prev_it);
                intervals.erase(it);
                intervals.insert(new_interval);
            } else if (val == prev_it->second + 1) {
                pair<int, int> new_interval = {prev_it->first, val};
                intervals.erase(prev_it);
                intervals.insert(new_interval);
            } else if (val == it->first - 1) {
                pair<int, int> new_interval = {val, it->second};
                intervals.erase(it);
                intervals.insert(new_interval);
            } else {
                intervals.insert(make_pair(val, val));
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> output;
        for (auto interval : intervals) {
            output.push_back({interval.first, interval.second});
        }
        return output;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// int arr[] = {};
	// vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

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