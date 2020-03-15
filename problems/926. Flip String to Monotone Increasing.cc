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
    int minFlipsMonoIncr(string S) {
        int n = S.size();
        vector<int> zeros_ahead(n, 0), zeros_behind(n, 0);

        for (int i = 0; i < n; ++i) {
        	if (i == 0) zeros_ahead[i] = S[i] == '0' ? 1 : 0;
        	else zeros_ahead[i] = zeros_ahead[i - 1] + (S[i] == '0' ? 1 : 0);
        }
        for (int i = n - 1; i >= 0; --i) {
        	if (i == n - 1) zeros_behind[i] = S[i] == '0' ? 1 : 0;
        	else zeros_behind[i] = zeros_behind[i + 1] + (S[i] == '0' ? 1 : 0);
        }
     //    for (int i = 0; i < n; ++i) cout << zeros_ahead[i] << " ";
     //    cout << endl;
    	// for (int i = 0; i < n; ++i) cout << zeros_behind[i] << " ";
     //    cout << endl;

        int ans = min(zeros_behind[0], n - zeros_behind[0]);
        for (int i = 0; i < n - 1; ++i) {
        	int flips = (i + 1 - zeros_ahead[i]) + zeros_behind[i + 1];
        	ans = min(ans, flips);
        }
        return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string S = "00011000";
	cout << sol.minFlipsMonoIncr(S) << endl;

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