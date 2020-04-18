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
// O(N^2 * W)
// N: # of words
// W: length of words
// union-find looks like O(N), but it actually has an amortized constant
// time operation
class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        vector<int> group(n);
        for (int i = 0; i < n; i++) group[i] = i;
    
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(A[i], A[j])) {
                    uni(i, j, group);
                }
            }
        }
        unordered_set<int> uniq;
        for (int i = 0; i < n; i++) {
            int a = find(i, group);
            uniq.insert(a);
        }
        return uniq.size();
    }
    int find(int x, vector<int>& group) {
        if (x != group[x]) group[x] = find(group[x], group);
        return group[x];
    }
    void uni(int x, int y, vector<int>& group) {
        int a = find(x, group);
        int b = find(y, group);
        if (a != b) group[a] = b;
    }
    bool isSimilar(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        
        int diff = -1;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (diff == -1) diff = i;
                else {
                    swap(s1[diff], s1[i]);
                    return s1 == s2;
                }
            }
        }
        return false;
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