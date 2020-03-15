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
    int missingNumber(vector<int>& arr) {
        int diff;
        if (abs(arr[1] - arr[0]) > abs(arr[2] - arr[1])) {
        	diff = arr[2] - arr[1];
        } else {
        	diff = arr[1] - arr[0];
        }

        for (int i = 0; i < arr.size() - 1; ++i) {
        	if (arr[i] + diff != arr[i + 1]) {
        		return arr[i] + diff;
        	}
        }
        return arr[0] - diff;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	const int a = 3;
	int arr[] = {15,13,11};
	vector<int> nums(arr, arr + a);
	cout << sol.missingNumber(nums) << endl;

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