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
// O(nlogn)
// class Solution {
// public:
//     bool isPossible(vector<int>& nums) {
//         unordered_map<int, priority_queue<int, vector<int>, greater<int> > > record;

//         for (int i = 0; i < nums.size(); i++) {
//         	int x = nums[i];

//         	if (record.find(x - 1) != record.end() && !record[x - 1].empty()) {
//         		int len = record[x - 1].top();
//         		record[x - 1].pop();
//         		record[x].push(len + 1);
//         	} else {
//         		record[x].push(1);
//         	}
//         }
//         bool valid = true;
//         for (unordered_map<int, priority_queue<int, vector<int>, greater<int> > >::iterator it = record.begin();
//         	 it != record.end(); it++) {
//         	while (!it->second.empty()) {
//         		if (it->second.top() < 3) return false;
//         		it->second.pop();
//         	}
//         }
//         return valid;
//     }
// };

// O(n)
class Solution {
public:
	bool isPossible(vector<int>& nums) {
		unordered_map<int, int> count, tails;
		for (int i = 0; i < nums.size(); i++) count[nums[i]]++;
		for (int i = 0; i < nums.size(); i++) {
			int x = nums[i];
			if (count[x] == 0) continue;
			count[x]--;
			// cout << "x: " << x << endl;
			if (tails[x - 1] > 0) {
				// cout << "connect" << endl;
				tails[x - 1]--;
				tails[x]++;
			} else if (count[x + 1] > 0 && count[x + 2] > 0) {
				// cout << "create new tail" << endl;
				count[x + 1]--;
				count[x + 2]--;
				tails[x + 2]++;
			} else {
				return false;
			}
		}
		return true;
	}
};


int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int n[] = {1,2,3,3,4,5};
	vector<int> nums(n, n + sizeof(n) / sizeof(int));

	cout << sol.isPossible(nums) << endl;

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