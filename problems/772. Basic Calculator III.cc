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
#include <numeric>
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

void traverse(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	traverse(root->left);
	traverse(root->right);
}

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    int calculate(string s) {
        long ans = 0, cur = 0, num = 0;
        char op = '+';
        
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '(') {
                int cnt = 1; 
                for (int j = i + 1; j < s.size(); j++) {
                    if (s[j] == '(') cnt++;
                    else if (s[j] == ')') cnt--;
                    if (cnt == 0) {
                        // cout << s.substr(i + 1, j - i - 1) << endl;
                        num = calculate(s.substr(i + 1, j - i -1));
                        // cout << num << endl;
                        i = j;
                        break;
                    }
                }
            } 
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == s.size() - 1) {
                if (op == '+') cur += num;
                else if (op == '-') cur -= num;
                else if (op == '*') cur *= num;
                else if (op == '/') cur /= num;
                
                if (s[i] == '+' || s[i] == '-' || i == s.size() - 1) {
                    ans += cur;
                    cur = 0;
                }
                num = 0;
                op = s[i];
            } 
        }
        return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// int arr[] = {};
	// vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

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