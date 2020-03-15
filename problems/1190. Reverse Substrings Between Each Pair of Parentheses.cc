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
// class Solution {
// public:
//     string reverseParentheses(string s) {
//         stack<char> st;
//         int i = 0, num_to_push = 0;
//         for (int i = 0; i < s.size(); ++i) {
//         	char c = s[i];
//         	if (c == ')') {
//         		string tmp = "";
//         		while (!st.empty() && st.top() != '(') {
//         			tmp += st.top();
//         			st.pop();
//         		}
//         		st.pop(); 	// pop '('
//         		for (int k = 0; k < tmp.size(); ++k) {
//         			st.push(tmp[k]);
//         		}
//         	} else st.push(c);
//         }

//         string ans = "";
//         while (!st.empty()) {
//         	ans = st.top() + ans;
//         	st.pop();
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string cur = "";
        for (int i = 0; i < s.size(); ++i) {
        	char c = s[i];
            if (c == '(') {
                if (cur.size()) {
                	st.push(cur);
                	cur = "";
                }
                st.push(string(1, c));
            } else if (c == ')') {
                while (!st.empty() && st.top() != "(") {
                    cur = st.top() + cur;
                    st.pop();
                }
                st.pop();
                reverse(cur.begin(), cur.end());
                st.push(cur);
                cur = "";
            } else {
                cur += c;
            }
        }
        st.push(cur);
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

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
	string s = "a(bcdefghijkl(mno)p)q";
	cout << sol.reverseParentheses(s) << endl;

}