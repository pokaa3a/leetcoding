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
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> vec1(26, 0), vec2(26, 0);
        if (s1.size() != s2.size()) return false;
        for (int i = 0; i < s1.size(); i++) {
            vec1[s1[i] - 'a']++;
            vec2[s2[i] - 'a']++;
        }
        return canBreak(vec1, vec2) || canBreak(vec2, vec1);
    }
    bool canBreak(vector<int> vec1, vector<int> vec2) {
        int i = 0, j = 0;
        while (i < 26 && j < 26) {
            if (vec1[i] == 0) {
                i++;
                continue;
            }
            if (vec2[j] == 0) {
                j++;
                continue;
            }

            if (i > j) return false;
            vec1[i]--;
            vec2[j]--;
        }
        return true;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s1 = "abe", s2 = "acd";
	cout << sol.checkIfCanBreak(s1, s2) << endl;

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