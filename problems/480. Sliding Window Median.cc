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
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> lo, hi;
        
        vector<double> ans;
        for (int i = 0; i < nums.size(); i++) {
            // insert new num
            lo.insert(nums[i]);
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));
            
            // erase old num
            if (i >= k) {
                int old_num = nums[i - k];
                if (old_num > *lo.rbegin()) {
                    hi.erase(hi.find(old_num));
                } else {
                    lo.erase(lo.find(old_num));
                }
            }
            
            // balance multisets
            int total = lo.size() + hi.size();
            // lo.size() == (total + 1) / 2
            while (lo.size() > (total + 1) / 2) {
                hi.insert(*lo.rbegin());
                lo.erase(prev(lo.end()));
            }
            while (lo.size() < (total + 1) / 2) {
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }
            
            if (i + 1 >= k) {
                if (k % 2 == 1) {
                    ans.push_back(double(*lo.rbegin()));
                } else {
                    double med = (double(*lo.rbegin()) + double(*hi.begin())) / 2;
                    ans.push_back(med);
                }
            }
        }
        return ans;
    }
};

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