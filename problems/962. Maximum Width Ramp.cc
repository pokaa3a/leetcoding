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
    int maxWidthRamp(vector<int>& A) {
        vector<int> vals(1, A[0]);
        vector<int> idxs(1, 0);
        int ans = 0;
        for (int i = 1; i < A.size(); ++i) {
        	int a = A[i];
        	
        	if (a < vals.back()) {
        		vals.push_back(a);
        		idxs.push_back(i);
        	} else {
        		ans = max(ans, i - bs(a, vals, idxs));
        	}
        }
        return ans;
    }

    // look for max val s.t. val <= x
    // return its idx
    int bs(int x, vector<int>& vals, vector<int>& idxs) {
    	int left = 0, right = vals.size() - 1;

    	while (left < right) {
    		int mid = (left + right) / 2;

    		if (vals[mid] <= x) {
    			right = mid;
    		} else {
    			left = mid + 1;
    		}
    	}
    	return idxs[left];
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {1, 0};
	vector<int> A(a, a + 2);

	cout << sol.maxWidthRamp(A) << endl;

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