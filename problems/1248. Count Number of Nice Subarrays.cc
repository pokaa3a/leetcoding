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
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n_odds = 0;
        vector<int> n_evens;

        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
        	if (nums[i] % 2 == 1) {
        		n_odds++;
        		n_evens.push_back(count);
        		count = 0;
        	} else {
        		count++;
        	}
        }
        n_evens.push_back(count);
        // for (int i = 0; i < n_evens.size(); ++i) {
        // 	cout << n_evens[i] << " ";
        // }
        // cout << endl;

        int ans = 0;
        for (int i = 0; i + k <= n_odds; ++i) {
        	ans += (n_evens[i] + 1) * (n_evens[i + k] + 1); 
        }
        return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int n[] = {2,2,2,1,2,2,1,2,2,2};
	vector<int> nums(n, n + 10);
	int k = 2;

	cout << sol.numberOfSubarrays(nums, k) << endl;

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