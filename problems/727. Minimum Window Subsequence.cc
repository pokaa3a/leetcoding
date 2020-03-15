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
// Solution-1: DP
// class Solution {
// public:
//     string minWindow(string S, string T) {
//         // dp[i][j]: the starting index of a substring in S[0~i] that
//         // 			 T[0~j] is its subsequence
//         // dp[i][j] = -1 if i < j
//         // if S[i] == T[j] : dp[i][j] = dp[i - 1][j - 1]
//         // if S[i] != T[j] : dp[i][j] = dp[i - 1][j]

//         vector<vector<int> > dp(S.size(), vector<int>(T.size(), -1));
//         // initialize dp[i][0]
//         for (int i = 0; i < S.size(); ++i) {
//         	if (S[i] == T[0]) dp[i][0] = i;
//         	else {
//         		if (i == 0) dp[i][0] = -1;
//         		else dp[i][0] = dp[i - 1][0];
//         	}
//         }

//         // fill the table
//         for (int i = 1; i < S.size(); ++i) {
//         	for (int j = 1; j <= min(i, (int)T.size() - 1); ++j) {
//         		if (S[i] == T[j]) dp[i][j] = dp[i - 1][j - 1];
//         		else dp[i][j] = dp[i - 1][j];
//         	}
//         }

//         int min_len = INT_MAX;
//         string res = "";

//         for (int i = 1; i < S.size(); ++i) {
//         	if (dp[i][T.size() - 1] > -1) {
//         		int len = i - dp[i][T.size() - 1] + 1;
//         		if (len < min_len) {
//         			res = S.substr(dp[i][T.size() - 1], len);
//         			min_len = len;
//         		}
//         	}
//         }
//         return res;
//     }
// };

// Solution-2: two pointers
class Solution {
public:
    string minWindow(string S, string T) {
        int left = 0, right = 0, min_left = -1, min_right = -1, min_len = INT_MAX;
        while (left < S.size() && right < S.size()) {
        	right = left;
        	int i;

        	for (i = 0; i < T.size() && right < S.size(); ++i, ++right) {
        		while (right < S.size() && S[right] != T[i]) right++;
        	}
        	if (i < T.size()) break;
        	right--;

        	left = right;
        	for (i = T.size() - 1; i >= 0 && left > 0; --i, --left) {
        		while (left >= 0 && S[left] != T[i]) left--;
        	}
        	if (i >= 0) break;
        	left++;

        	if (right - left + 1 < min_len) {
        		min_left = left;
        		min_right = right;
        		min_len = right - left + 1;
        		// cout << "len: " << min_len << endl;
        	}
        	left++;
        }
        if (min_left == -1) return "";
        return S.substr(min_left, min_right - min_left + 1);
    }
};

void traverse(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	traverse(root->left);
	traverse(root->right);
}

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	// string S = "abcdebdde", T = "bde";
	// string S = "ffynmlzesdshlvugsigobutgaetsnjlizvqjdpccdylclqcbghhixpjihximvhapymfkjxyyxfwvsfyctmhwmfjyjidnfryiyajmtakisaxwglwpqaxaicuprrvxybzdxunypzofhpclqiybgniqzsdeqwrdsfjyfkgmejxfqjkmukvgygafwokeoeglanevavyrpduigitmrimtaslzboauwbluvlfqquocxrzrbvvplsivujojscytmeyjolvvyzwizpuhejsdzkfwgqdbwinkxqypaphktonqwwanapouqyjdbptqfowhemsnsl";
	// string T = "ntimcimzah";
	string S = "jmeqksfrsdcmsiwvaovztaqenprpvnbstl";
	string T = "l";
	cout << sol.minWindow(S, T) << endl;

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