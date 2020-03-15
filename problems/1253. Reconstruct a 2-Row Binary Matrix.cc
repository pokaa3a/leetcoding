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
    vector<vector<int> > reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int> > ans(2, vector<int>(colsum.size(), 0));
        int n_0s = 0, n_1s = 0, n_2s = 0;
        for (int i = 0; i < colsum.size(); ++i) {
        	if (colsum[i] == 0) n_0s++;
        	else if (colsum[i] == 1) n_1s++;
        	else n_2s++;
        }
        upper -= n_2s;
        lower -= n_2s;
        if (upper < 0 || lower < 0) return vector<vector<int> >();
        if (upper + lower != n_1s) return vector<vector<int> >();

        for (int i = 0; i < colsum.size(); ++i) {
        	if (colsum[i] == 2) {
        		ans[0][i] = 1;
        		ans[1][i] = 1;
        	} else if (colsum[i] == 1) {
        		if (upper > 0) {
        			ans[0][i] = 1;
        			upper--;
        		} else {
        			ans[1][i] = 1;
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