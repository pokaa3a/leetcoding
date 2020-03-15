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

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int> >& nums) {
    	map<int, vector<pair<int, int> > > heap;
    	int max_val = 0;

    	for (int i = 0; i < nums.size(); ++i) {
    		if (heap.find(nums[i][0]) == heap.end()) {
    			heap[nums[i][0]] = vector<pair<int, int> >();
    		}
    		heap[nums[i][0]].push_back(make_pair(i, 0));
    		max_val = max(max_val, nums[i][0]);
    	}

    	vector<int> res(2, 0);
    	int range = INT_MAX;
    	while(true) {
    		int min_val = heap.begin()->first;
    		int cur_range = max_val - min_val;
    		if (cur_range < range) {
    			range = cur_range;
    			res[0] = min_val;
    			res[1] = max_val;
    		}

    		vector<pair<int, int> >& vec = heap.begin()->second;
    		int list_idx = vec.back().first;
    		int idx = vec.back().second;
    		// pop out smallest pointer
    		vec.pop_back();
    		if (vec.empty()) heap.erase(min_val);

    		// move pointer
    		int new_idx = idx + 1;
    		if (new_idx == nums[list_idx].size()) return res;
    		int new_val = nums[list_idx][new_idx];
    		max_val = max(max_val, new_val);
    		if (heap.find(new_val) == heap.end()) heap[new_val] = vector<pair<int, int> >();
    		heap[new_val].push_back(make_pair(list_idx, new_idx));
    	}
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

	/* [2-D vector] */
	vector<vector<int> > nums;
	// int n1[] = {4,10,15,24,26};
	int n1[] = {1,4,7,10,13};
	// int n2[] = {0,9,12,20};
	int n2[] = {2,5,8,11,13};
	// int n3[] = {5,18,22,30};
	int n3[] = {3,6,9,12};
	nums.push_back(vector<int>(n1, n1 + 5));
	nums.push_back(vector<int>(n2, n2 + 5));
	nums.push_back(vector<int>(n3, n3 + 4));

	vector<int> res = sol.smallestRange(nums);
	cout << "ans: " << res[0] << ", " << res[1] << endl;

	/* [String] */
	// string str = "";

}