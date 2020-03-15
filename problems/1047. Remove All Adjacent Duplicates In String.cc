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

/* Solution */
class Solution {
public:
    string removeDuplicates(string S) {
        string ans = "";
        stack<char> st;
        for (int i = 0; i < S.size(); ++i) {
        	char c = S[i];
        	if (!st.empty() && st.top() == c) st.pop();
        	else st.push(c);
        }
        while (!st.empty()) {
        	ans += st.top();
        	st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	string S = "abbaca";
	cout << sol.removeDuplicates(S) << endl;
}