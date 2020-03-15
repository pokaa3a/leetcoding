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
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int arr2_left = 0, arr2_right = arr2.size() - 1;
        int arr3_left = 0, arr3_right = arr3.size() - 1;
        vector<int> ans;
        for (int i = 0; i < arr1.size(); ++i) {
        	int n = arr1[i];
        	arr2_left = lower_bound(arr2.begin() + arr2_left, arr2.end(), n) - arr2.begin();
        	arr3_left = lower_bound(arr3.begin() + arr3_left, arr3.end(), n) - arr3.begin();
        	if (arr2_left > arr2_right || arr3_left > arr3_right) continue;
        	if (arr2[arr2_left] == n && arr3[arr3_left] == n) {
        		ans.push_back(n);
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
	// const int a = 1;
	int a1[] = {1,2,3,4,9};
	int a2[] = {1,2,5,7,9};
	int a3[] = {1,3,4,5,9};
	vector<int> arr1(a1, a1 + 5);
	vector<int> arr2(a2, a2 + 5);
	vector<int> arr3(a3, a3 + 5);
	vector<int> ans = sol.arraysIntersection(arr1, arr2, arr3);
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;

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