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

class BIT {
private:
	vector<int> BITtree;
	int n;
public:
	BIT(vector<int>& arr) {
		n = arr.size();
		BITtree.resize(n + 1, 0);
		for (int i = 0; i < n; ++i) update_BIT(i, arr[i]);
	}
	void update_BIT(int index, int val) {
		index = index + 1;
		while (index <= n) {
			BITtree[index] += val;
			index += index & (-index);
		}
	}
	int get_sum(int index) {
		int sum = 0;
		index = index + 1;
		while (index > 0) {
			sum += BITtree[index];
			index -= index & (-index);
		}
		return sum;
	}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        map<int, int> val2idx;
        while (!s.empty()) {
        	val2idx[*s.begin()] = val2idx.size();
        	s.erase(s.begin());
        }

        vector<int> arr(val2idx.size(), 0);
        BIT* bit = new BIT(arr);

        vector<int> ans(nums.size(), 0);
        for (int i = nums.size() - 1; i >= 0; --i) {
        	int idx = val2idx[nums[i]];
        	if (idx == 0) {
        		ans[i] = 0;
        	} else {
        		ans[i] = bit->get_sum(idx - 1);
        	}
        	bit->update_BIT(idx, 1);
        }
        return ans;
    }
};


int main() {
	/* Solution */

	/* Test cases */
	int n[] = {5,2,6,1};
	vector<int> nums(n, n + 4);

	Solution sol;
	vector<int> ans = sol.countSmaller(nums);
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";

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