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
//     string minRemoveToMakeValid(string s) {
//     	stack<string> st;
//     	string cur = "";
//     	for (int i = 0; i < s.size(); ++i) {
//     		char c = s[i];
//     		if (c == '(') {
//     			st.push(cur);
//     			cur = "";
//     			st.push("(");
//     		} else if (c == ')') {
//     			if (cur.size() > 0) st.push(cur);
//     			cur = "";

//     			string valid = "";
//     			while (!st.empty() && st.top() != "(") {
//     				valid = st.top() + valid;
//     				st.pop();
//     			}
//     			if (st.empty()) {
//     				st.push(valid);
//     			} else {
//     				st.pop();
//     				valid = "(" + valid + ")";
//     				st.push(valid);
//     			}
//     		} else {
//     			cur = cur + c;
//     		}
//     	}
//     	st.push(cur);
//     	string ans = "";
//     	while (!st.empty()) {
//     		if (st.top() != "(") {
//     			ans = st.top() + ans;
//     		}
//     		st.pop();
//     	}
//     	return ans;
//     }
// };
class Solution {
public:
    string minRemoveToMakeValid(string s) {
       	stack<int> st;
       	for (int i = 0; i < s.size(); ++i) {
       		if (s[i] == '(') st.push(i);
       		else if (s[i] == ')') {
       			if (!st.empty()) st.pop();
       			else s[i] = '*';
       		}
       	}
       	while (!st.empty()) {
       		s[st.top()] = '*';
       		st.pop();
       	}
       	s.erase(remove(s.begin(), s.end(), '*'), s.end());
       	return s;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s = "(a(b(c)d)";
	cout << sol.minRemoveToMakeValid(s) << endl;

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

}