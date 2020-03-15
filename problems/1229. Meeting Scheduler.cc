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
    vector<int> minAvailableDuration(vector<vector<int> >& slots1, vector<vector<int> >& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());

        vector<int> ans(2, 0);
        int i = 0, j = 0;
        while (i < slots1.size() && j < slots2.size()) {
        	vector<int> A = slots1[i];
        	vector<int> B = slots2[j];

        	if (A[1] >= B[0] && A[1] <= B[1]) {			// B[0] <= A[1] <= B[1]
        		int left = max(A[0], B[0]);
        		if (A[1] - left >= duration) {
        			ans[0] = left;
        			ans[1] = left + duration;
        			return ans;
        		}
        		i++;
        	} else if (B[1] >= A[0] && B[1] <= A[1]) {	// A[0] <= B[1] <= A[1]
        		int left = max(A[0], B[0]);
        		if (B[1] - left >= duration) {
        			ans[0] = left;
        			ans[1] = left + duration;
        			return ans;
        		}
                j++;
        	} else {
        		if (A[0] < B[0]) i++;
        		else j++;
        	}
        }
        return vector<int>();
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
	const int rows = 3;
	const int cols = 2;
	int arr1[rows][cols] = {};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}

	/* [String] */
	// string str = "";

}