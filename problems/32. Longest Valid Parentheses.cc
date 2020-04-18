#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution1 {
public:
	int longestValidParentheses(string s) {
		stack<int> stk;
		int res = 0, count = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '(') {
				stk.push(count);
				count = 0;
			} else if (!stk.empty()) {
				count += 1 + stk.top();
				stk.pop();
				res = max(res, count);
			} else {
				count = 0;
			}
		}
		return res * 2;
	}
};

// DP
class Solution2 {
public:
	int longestValidParentheses(string s) {
		vector<int> dp(s.size(), 0);

		int output = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ')') {
				if (i > 0 && s[i - 1] == '(') {
					dp[i] = (i < 2 ? 0 : dp[i - 2]) + 2;
				} else {
					int len = i < 1 ? 0 : dp[i - 1];
					if (i - len - 1 >= 0 && s[i - len - 1] == '(') {
						dp[i] = len + (i - len - 2 >= 0 ? dp[i - len - 2] : 0) + 2; 
					}
				}
				output = max(output, dp[i]);
			}
		}
		return output;
	}
};

// Stack
class Solution3 {
public:
	int longestValidParentheses(string s) {
		stack<int> stk;	// last unvalid index
		stk.push(-1);

		int output = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				stk.push(i);
			} else {
				stk.pop();
				if (stk.empty()) {
					stk.push(i);
				} else {
					int valid_len = i - stk.top();
					output = max(output, valid_len);
				}
			}
		}
		return output;
	}
};

// No extra space
class Solution4 {
public:
	int longestValidParentheses(string s) {
		int left_count = 0, right_count = 0;
		int output = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				left_count++;
			} else {
				right_count++;
			}

			if (left_count == right_count) {
				output = max(output, right_count * 2);
			} else if (right_count >left_count) {
				left_count = 0;
				right_count = 0;
			}
		}

		left_count = 0; 
		right_count = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == '(') {
				left_count++;
			} else {
				right_count++;
			}

			if (left_count == right_count) {
				output = max(output, left_count * 2);
			} else if (left_count > right_count) {
				left_count = 0;
				right_count = 0;
			}
		}
		return output;
	}
};

int main() {
	string s1 = "()(())";
	Solution2 sol;
	cout << sol.longestValidParentheses(s1) << endl;
}