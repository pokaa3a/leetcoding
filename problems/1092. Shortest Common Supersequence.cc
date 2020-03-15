#include <iostream>
#include <string>
#include <vector>
using namespace std;

// class Solution {
// public:
// 	string shortestCommonSupersequence(string str1, string str2) {
// 		string lcs_str = lcs(str1, str2);

// 		string res = "";
// 		int i = 0, j = 0;
// 		for (int x = 0; x < lcs_str.size(); ++x) {
// 			char c = lcs_str[x];
// 			while (str1[i] != c) {
// 				res += str1[i];
// 				i++;
// 			}
// 			while (str2[j] != c) {
// 				res += str2[j];
// 				j++;
// 			}
// 			i++;
// 			j++;
// 			res += c;
// 		}
// 		return res + str1.substr(i) + str2.substr(j);
// 	}
// private:
// 	string lcs(string & A, string& B) {
// 		int n = A.size(), m = B.size();
// 		vector<vector<string> > dp(n + 1, vector<string>(m + 1, ""));

// 		for (int i = 0; i < n; ++i) {
// 			for (int j = 0; j < m; ++j) {
// 				if (A[i] == B[j]) {
// 					dp[i + 1][j + 1] = dp[i][j] + A[i];
// 				} else {
// 					dp[i + 1][j + 1] = dp[i][j + 1].size() > dp[i + 1][j].size() ? dp[i][j + 1] : dp[i + 1][j];
// 				}
// 			}
// 		}
// 		return dp[n][m];
// 	}
// };

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs_str = lcs(str1, str2);

        string ans = "";
        int i = 0, j = 0;
        for (int k = 0; k < lcs_str.size(); ++k) {
        	while (str1[i] != lcs_str[k]) {
        		ans += str1[i++];
        	}
        	while (str2[j] != lcs_str[k]) {
        		ans += str2[j++];
        	}
        	i++;
        	j++;
        	ans += lcs_str[k];
        }
        ans += str1.substr(i) + str2.substr(j);
        return ans;
    }
    string lcs (string A, string B) {
    	int n = A.size(), m = B.size();
    	vector<vector<string> > dp(n + 1, vector<string>(m + 1, ""));

    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < m; ++j) {
    			if (A[i] == B[j]) {
    				dp[i + 1][j + 1] = dp[i][j] + A[i];
    			} else {
    				dp[i + 1][j + 1] = dp[i + 1][j].size() > dp[i][j + 1].size() ? dp[i + 1][j] : dp[i][j + 1];
    			}
    		}
    	}
    	return dp[n][m];
    }
};

int main() {
	string str1 = "cef";
	string str2 = "gceffga";
	Solution sol;
	cout << sol.shortestCommonSupersequence(str1, str2) << endl;
}