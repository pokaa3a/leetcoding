#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int s_len = s.size(), p_len = p.size();
    vector<vector<bool>> dp(s_len + 1, vector<bool>(p_len + 1, false));
    dp[0][0] = true;
    
    for (int i = 0; i <= s_len; i++) {
      for (int j = 1; j <= p_len; j++) {
        bool match = i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        
        if (j + 1 <= p_len && p[j + 1 - 1] == '*') {
          dp[i][j + 1] = dp[i][j - 1] || (match && (i == 0 ? dp[0][j + 1] : dp[i - 1][j + 1]));
          j++;
        } else {
          dp[i][j] = match && dp[i - 1][j - 1];
        }
      }
    }
    return dp[s_len][p_len];
  }
};

// class Solution {
// public:
// bool isMatch(string s, string p) {
//     return dfs(s, p);
// }
// private:
//     bool dfs(string s, string p) {
//          if (p.length() == 0) {
//          if (s.length() == 0) return true;
//          else return false;
//     }

//     if (p.length() > 1 && p[1] == '*') {
//          if (p[0] == '.') {	// '.*'
//              for (int i = 0; i <= s.length(); ++i) {
//                  if (dfs(s.substr(i), p.substr(2))) return true;
//              }
//              return false;
//          } else {			// '{c}*'
//              char c = p[0];
//              if (dfs(s.substr(0), p.substr(2))) return true;
//              for (int i = 0; s[i] == c; ++i) {
//                 if (dfs(s.substr(i + 1), p.substr(2))) return true;
//              }
//              return false;
//          }
//      }
//          if (s.length() < 1) return false;
//          if (p[0] == '.') {
//              return dfs(s.substr(1), p.substr(1));
//          } 
//          // p[0] == 'a' to 'z'
//          return p[0] == s[0] && dfs(s.substr(1), p.substr(1));
//      }
// };

int main() {
	string s = "mississippi";
	string p = "mis*is*p*";
	Solution sol;
	cout << sol.isMatch(s, p) << endl;
}