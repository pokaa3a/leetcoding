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
// DP
// class Solution {
// public:
//     vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<vector<int>> dp_1(n, vector<int>(2, 0)), dp_2(n, vector<int>(3, 0)), dp_3(n, vector<int>(4, 0));
        
//         // 1
//         int cur_sum = 0, max_sum = 0, max_idx = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             cur_sum += nums[i];
//             if (i >= k - 1) {
//                 if (cur_sum > max_sum) {
//                     max_sum = cur_sum;
//                     dp_1[i] = {max_sum, i - (k - 1)};
//                 } else {
//                     dp_1[i] = dp_1[i - 1];
//                 }
//                 cur_sum -= nums[i - (k - 1)];
//             }
//         }
        
//         // 2
//         cur_sum = 0;
//         for (int i = k; i < nums.size(); i++) {
//             cur_sum += nums[i];
//             if (i >= 2 * k - 1) {
//                 if (dp_2[i - 1][0] >= cur_sum + dp_1[i - k][0]) {
//                     dp_2[i] = dp_2[i - 1];
//                 } else {
//                     dp_2[i] = {cur_sum + dp_1[i - k][0], dp_1[i - k][1], i - (k - 1)};
//                 }
//                 cur_sum -= nums[i - (k - 1)];
//             }
//         }
        
//         // 3
//         cur_sum = 0, max_sum = 0;
//         vector<int> output;
//         for (int i = 2 * k; i < nums.size(); i++) {
//             cur_sum += nums[i];
//             if (i >= 3 * k - 1) {
//                 if (dp_3[i - 1][0] >= cur_sum + dp_2[i - k][0]) {
//                     dp_3[i] = dp_3[i - 1];
//                 } else {
//                     dp_3[i] = {cur_sum + dp_2[i - k][0], dp_2[i - k][1], dp_2[i - k][2], i - (k - 1)};
//                 }
//                 if (dp_3[i][0] > max_sum) {
//                     max_sum = dp_3[i][0];
//                     output = vector<int>(dp_3[i].begin() + 1, dp_3[i].end());
//                 }
//                 cur_sum -= nums[i - (k - 1)];
//             }
//         }
//         return output;
//     }
// };

// Ad-Hoc
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> W(n - k + 1, 0);
        int cur_sum = 0;
        for (int i = 0; i < n; i++) {
            cur_sum += nums[i];
            if (i >= k - 1) {
                W[i - (k - 1)] = cur_sum;
                cur_sum -= nums[i - (k - 1)];
            }
        }
        // for (int x : W) cout << x << " ";
        // cout << endl;
        
        int n_w = n - k + 1;
        vector<int> left_best(n_w, 0), right_best(n_w, 0);
        int best = 0;
        for (int i = 0; i < n_w; i++) {
            if (W[i] > W[best]) {
                best = i;
            }
            left_best[i] = best;
        }
        // for (int x : left_best) cout << x << " ";
        // cout << endl;

        best = n_w - 1;
        for (int i = n_w - 1; i >= 0; i--) {
            if (W[i] >= W[best]) {
                best = i;
            }
            right_best[i] = best;
        }
        // for (int x : right_best) cout << x << " ";
        // cout << endl;
        
        int max_sum = 0;
        vector<int> output(3);
        for (int i = k; i < n_w - k; i++) {
            int left = W[left_best[i - k]];
            int mid = W[i];
            int right = W[right_best[i + k]];
            if (left + mid + right > max_sum) {
                max_sum = left + mid + right;
                output = {left_best[i - k], i, right_best[i + k]};
            }
        }
        return output;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<int> nums = {1,2,1,2,6,7,5,1};
	int k = 2;
	vector<int> res = sol.maxSumOfThreeSubarrays(nums, k);
	for (int x : res) cout << x << " ";
	cout << endl;

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