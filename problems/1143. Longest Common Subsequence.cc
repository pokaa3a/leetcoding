#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int n1 = text1.length(), n2 = text2.length();
		vector<vector<int> > dp(n1 + 1, vector<int>(n2 + 1, -1));
		return compute(n1, n2, dp, text1, text2);
	}
private:
	int compute(int n1, int n2, vector<vector<int> >& dp, string& text1, string& text2) {
		if (n1 == 0 || n2 == 0) {
			dp[n1][n2] = 0;
			return dp[n1][n2];
		}
		if (dp[n1][n2] != -1) {
			return dp[n1][n2];
		}
		if (text1[n1 - 1] == text2[n2 - 1]) {
			dp[n1][n2] = compute(n1 - 1, n2 - 1, dp, text1, text2) + 1;
		} else {
			dp[n1][n2] = max(compute(n1, n2 - 1, dp, text1, text2), 
							 compute(n1 - 1, n2, dp, text1, text2));
		}
		return dp[n1][n2];
	}
};

int main() {
	string text1 = "abc";
	string text2 = "def";
	Solution sol;
	cout << sol.longestCommonSubsequence(text1, text2) << endl;
}