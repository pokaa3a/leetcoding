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
    bool isValid(string S) {
        if (S == "abc") return true;
        if (S.size() < 3) return false;

        string last_2 = "";
        stack<char> st;
        for (int i = 0; i < S.size(); ++i) {
        	if (st.empty()) {
        		st.push(S[i]);
        		continue;
        	}
        	if (S[i] == 'a' || S[i] == 'b') st.push(S[i]);
        	else {
        		if (st.size() >= 2) {
        			char last_1 = st.top(); st.pop();
        			char last_2 = st.top(); st.pop();
        			if (last_2 == 'a' && last_1 == 'b') {
        				continue;
        			} else {
        				st.push(last_2);
        				st.push(last_1);
        				st.push(S[i]);
        			}
        		} else {
        			st.push(S[i]);
        		}
        	}
        }
        return st.size() == 0 ? true : false;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	string S = "cababc";
	cout << sol.isValid(S) << endl;

}