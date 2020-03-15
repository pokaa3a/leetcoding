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
private:
	int ans;
public:
    int minCameraCover(TreeNode* root) {
        ans = 0;

        if (dfs(root) == -1) return ans + 1;
        return ans;
    }

    // return
    //  0: is covered
    //  1: is camera
    // -1: not covered
    int dfs(TreeNode* root) {
    	if (!root) return 0;

    	int left = dfs(root->left);
    	int right = dfs(root->right);

    	if (left == -1 || right == -1) {
    		ans++;
    		return 1;
    	}
    	if (left == 1 || right == 1) {
    		return 0;
    	}
    	if (left == 0 && right == 0) {
    		return -1;
    	}

    	return 0;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {1,2,3};
	vector<int> A(a, a + 3);

	vector<int> ans = sol.pancakeSort(A);
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
	cout << endl;

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