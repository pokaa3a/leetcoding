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
    int smallestCommonElement(vector<vector<int> >& mat) {
        vector<int> record(10001, 0);
        int rows = mat.size();
        for (int c = 0; c < mat[0].size(); ++c) {
        	for (int r = 0; r < rows; ++r) {
        		if (c >= mat[r].size()) return -1;
        		int n = mat[r][c];
        		if (++record[n] == rows) return n;
        	}
        }
        return -1;
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
	const int rows = 4;
	const int cols = 5;
	int arr[rows][cols] = {{1,2,3,4,5}, {2,4,5,8,10}, {3,5,7,9,11}, {1,3,5,7,9}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}
	cout << sol.smallestCommonElement(grid) << endl;

	/* [String] */
	// string str = "";

}