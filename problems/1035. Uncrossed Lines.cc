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

const int MOD = 1000000007;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Solution */
// class Solution {
// public:
//     int maxUncrossedLines(vector<int>& A, vector<int>& B) {
//         vector<int>& X = A.size() < B.size() ? A : B;
//         vector<int>& Y = A.size() < B.size() ? B : A;

//         vector<vector<int> > dp(X.size(), vector<int>(Y.size(), 0));
//         map<int, int> X_last;
//         for (int i = 0; i < X.size(); ++i) {
//         	X_last[X[i]] = i;
//         	for (int j = 0; j < Y.size(); ++j) {
//         		if (X_last.find(Y[j]) != X_last.end()) {
//         			if (j == 0) dp[i][j] = 1;
//         			else {
//         				int x_i = X_last[Y[j]];
//         				dp[i][j] = max((x_i == 0 ? 0 : dp[x_i - 1][j - 1]) + 1, dp[i][j - 1]);
//         			}
//         		} else {
//         			dp[i][j] = j == 0 ? 0 : dp[i][j - 1];
//         		}
//         	}
//         }
//         return dp[X.size() - 1][Y.size() - 1];
//     }
// };

// Longest common subsequence
class Solution {
public:
	int maxUncrossedLines(vector<int>& A, vector<int>& B) {
		int n = A.size(), m = B.size();
		vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i < n + 1; ++i) {
			for (int j = 1; j < m + 1; ++j) {
				dp[i][j] = A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[n][m];
	}
};


int main() {
	// Solution
	Solution sol;

	// Test cases
	int a[] = {1,3,7,1,7,5};
	int b[] = {1,9,2,5,1};
	vector<int> A(a, a + 6);
	vector<int> B(b, b + 5);

	cout << sol.maxUncrossedLines(A, B) << endl;
}