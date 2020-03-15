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
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int> >& queries) {
        int n = colors.size();
        vector<int> dist_1(n, INT_MAX);
        vector<int> dist_2(n, INT_MAX);
        vector<int> dist_3(n, INT_MAX);
        int last_1 = -1, last_2 = -1, last_3 = -1;
        // forward
        for (int i = 0; i < n; ++i) {
        	if (colors[i] == 1) last_1 = i;
        	else if (colors[i] == 2) last_2 = i;
        	else last_3 = i;

        	if (last_1 >= 0) dist_1[i] = abs(last_1 - i);
        	if (last_2 >= 0) dist_2[i] = abs(last_2 - i);
        	if (last_3 >= 0) dist_3[i] = abs(last_3 - i);
        }

        // backward
        last_1 = -1;
        last_2 = -1;
        last_3 = -1;
        for (int i = n - 1; i >= 0; --i) {
        	if (colors[i] == 1) last_1 = i;
        	else if (colors[i] == 2) last_2 = i;
        	else last_3 = i;

        	if (last_1 >= 0) dist_1[i] = min(dist_1[i], abs(last_1 - i));
        	if (last_2 >= 0) dist_2[i] = min(dist_2[i], abs(last_2 - i));
        	if (last_3 >= 0) dist_3[i] = min(dist_3[i], abs(last_3 - i));
        }

        vector<int> ans(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++i) {
        	int idx = queries[i][0];
        	if (queries[i][1] == 1) {
        		ans[i] = dist_1[idx] == INT_MAX ? -1 : dist_1[idx];
        	} else if (queries[i][1] == 2) {
        		ans[i] = dist_2[idx] == INT_MAX ? -1 : dist_2[idx];
        	} else {	// 3
        		ans[i] = dist_3[idx] == INT_MAX ? -1 : dist_3[idx];
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