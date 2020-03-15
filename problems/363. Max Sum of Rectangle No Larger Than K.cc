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

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int> >& matrix, int k) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        int ans = INT_MIN;

        for (int l = 0; l < m; ++l) {
        	vector<int> sums(n, 0);
        	for (int r = l; r < m; ++r) {
        		set<int> s;
        		s.insert(0);
        		int cur = 0;
        		for (int i = 0; i < n; ++i) {
        			sums[i] += matrix[i][r];
        			cur += sums[i];
        			set<int>::iterator it = s.lower_bound(cur - k);
        			if (it != s.end()) ans = max(ans, cur - *it);
        			s.insert(cur);
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
	const int rows = 2;
	const int cols = 3;
	int arr[rows][cols] = {{1,0,1}, {0,-2,3}};
	int k = 2;
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}
	cout << sol.maxSumSubmatrix(grid, k) << endl;

	/* [String] */
	// string str = "";

}