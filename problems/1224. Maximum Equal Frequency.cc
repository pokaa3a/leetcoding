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
    int maxEqualFreq(vector<int>& nums) {
        vector<int> count(100001, 0);
        vector<int> freq(100001, 0);
        int N = nums.size();
        int ans = 1;
        for (int n = 1; n <= N; ++n) {
        	int a = nums[n - 1];
        	freq[count[a]]--;
        	int c = ++count[a];
        	freq[c]++;

        	if (freq[c] * c == n && n < N) ans = n + 1;
        	else {
        		int d = n - freq[c] * c;
        		if (freq[d] == 1 && (d == c + 1 || d == 1)) ans = n;
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
	int arr[] = {2,2,1,1,5,3,3,5};
	vector<int> nums(arr, arr + 8);
	cout << sol.maxEqualFreq(nums) << endl;

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