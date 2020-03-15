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
class Solution {
public:
    string removeOuterParentheses(string S) {
        int left = 0;
        stack<char> st;
        string ans = "";
        for (int i = 0; i < S.size(); ++i) {
        	if (S[i] == '(') st.push(S[i]);
        	else {
        		if (!st.empty() && st.top() == '(') st.pop();
        		if (st.empty()) {
        			ans += S.substr(left + 1, i - left - 1);
        			left = i + 1;
        		}
        	}
        }
        return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	string S = "()()";
	cout << sol.removeOuterParentheses(S) << endl;
}