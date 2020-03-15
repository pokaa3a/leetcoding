#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution1 {
public:
	int longestValidParentheses(string s) {
		stack<string> st;
		int maximum = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '(') {
				st.push("(");
			} else {
				int valid = 0;
				bool endWithValid = false;
				while (st.size()) {
					if (st.top() != "(" && st.top() != ")") {
						valid += stoi(st.top());
						st.pop();
					} else if (st.top() == "(") {
						if (endWithValid) break;
						valid += 2;
						st.pop();
						endWithValid = true;
					} else {
						break;
					}
				}
				if (valid) st.push(to_string(valid));
				if (!endWithValid) st.push(")");
				maximum = max(valid, maximum);
			}
		}
		return maximum;
	}
};

class Solution2 {
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

int main() {
	string s1 = "()(())";
	Solution2 sol;
	cout << sol.longestValidParentheses(s1) << endl;
}