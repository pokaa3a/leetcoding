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

class BIT {
private:
	vector<int> bit_tree;
	int n;
public:
	BIT(vector<int>& arr) {
		n = arr.size();
		bit_tree.resize(n + 1, 0);
		for (int i = 0; i < n; ++i) update_tree(i, arr[i]);
	}
	void update_tree(int idx, int val) {
		idx = idx + 1;
		while (idx <= n) {
			bit_tree[idx] += val;
			idx += idx & (-idx);
		}
	}
	int get_sum(int idx) {
		int sum = 0;
		idx = idx + 1;
		while (idx > 0) {
			sum += bit_tree[idx];
			idx -= idx & (-idx);
		}
		return sum;
	}
};

const int MOD = 1000000007;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
    	set<int> s;
    	for (int i = 0; i < nums.size(); ++i) {
    		s.insert(nums[i]);
    		s.insert((int)ceil(double(nums[i]) / 2) - 1);
    	}
    	unordered_map<int, int> num2idx;
    	for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
    		num2idx[(int)*it] = num2idx.size();
    	}
    	int n = num2idx.size();
    	vector<int> arr(n, 0);

        BIT* bit = new BIT(arr);
        int ans = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
        	ans += bit->get_sum(num2idx[(int)ceil(double(nums[i]) / 2) - 1]);
        	bit->update_tree(num2idx[nums[i]], 1);
        }
        return ans;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int n[] = {2,4,3,5,1};
	vector<int> nums(n, n + 5);
	cout << sol.reversePairs(nums) << endl;

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

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